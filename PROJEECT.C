#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#define MAX_PLACES     20
#define MAX_NEIGHBORS  8
#define MAX_ROADS      40
#define MAX_NEARBY     6
#define NAME_LEN       64
#define DESC_LEN       220
#define SMALL_LEN      32
#define MAX_ROUTES     15
#define ROUTES_FILE    "routes.txt"
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define MAGENTA "\033[35m"
#define GRAY    "\033[90m"

/* ---------------- enums ---------------- */
typedef enum { 
    DHAKA, CHATTOGRAM, SYLHET, RAJSHAHI, KHULNA, BARISHAL, RANGPUR, MYMENSINGH, DIVISION_COUNT 
} Division;

typedef enum { 
    EXCELLENT, GOOD, AVERAGE, POOR 
} RoadCondition;

typedef enum { 
    BUS, CAR, MOTORCYCLE, MICROBUS 
} VehicleType;

typedef enum { 
    WEIGHT_DISTANCE, WEIGHT_TIME, WEIGHT_COST 
} WeightMode;

/* ---------------- data structures ---------------- */
typedef struct { //tourist place er info
    char name[NAME_LEN];
    Division division;
    char district[NAME_LEN];
    char description[DESC_LEN];
    char openingTime[SMALL_LEN];
    char closingTime[SMALL_LEN];
    int entryFee;
    char bestSeason[SMALL_LEN];
    double lat, lon;
    char nearby[MAX_NEARBY][NAME_LEN];
    int nearbyCount;
} Place; //struct দিয়ে একটা tourist place-এর সব data এক object-এর মধ্যে রাখা যায়।

typedef struct {
    char roadName[64];
    int from, to;
    double distanceKm;
    int speedLimit;
    RoadCondition condition;
    char description[DESC_LEN];
    double busFare, carFuelCost, motorcycleCost, microbusCost;
} Road;

typedef struct {//complete route-এর information
    int placeIdx[MAX_PLACES];
    int placeCount;
    int roadIdx[MAX_PLACES];
    int roadCount;
    double totalDistance, totalTime, totalCost;
} Route;

/* ---------------- global state ---------------- */
static Place places[MAX_PLACES];
static int placeCount = 0;

static Road roads[MAX_ROADS];
static int roadCount = 0;
static int physicalRoadCount = 0;

//এই place থেকে কোন কোন road বের হয়েছে seta bole
static int adjIndex[MAX_PLACES][MAX_NEIGHBORS];
static int adjCount[MAX_PLACES];

/*Console UI helpers*/

static void printDivider(char ch, int length) {
    printf(GRAY);
    for (int i = 0; i < length; ++i) putchar(ch);
    printf(RESET "\n");
}

static void printThinDivider(void) {
    printf(GRAY "------------------------------------------------------------" RESET "\n");
}

static void printHeader(const char *title) {
    printDivider('=', 60);
    printf(BOLD MAGENTA "  %s" RESET "\n", title);
    printDivider('=', 60);
}

static void printError(const char *msg)   { printf(RED BOLD "[ERROR] " RESET RED "%s" RESET "\n", msg); }
static void printSuccess(const char *msg) { printf(GREEN BOLD "[OK] " RESET GREEN "%s" RESET "\n", msg); }
static void printInfo(const char *msg)    { printf(CYAN "[INFO] " RESET "%s\n", msg); }

static void pauseConsole(void) {
    printf(GRAY "\nPress ENTER to continue..." RESET);
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

static void printWelcomeBanner(void) {
    printDivider('=', 60);
    printf(BOLD CYAN "         SMART ROUTE PLANNER - CONSOLE EDITION" RESET "\n");
    printDivider('=', 60);
}

/*Small utilities */

static const char *divisionToString(Division d) {
    switch (d) {
        case DHAKA:      return "Dhaka";
        case CHATTOGRAM: return "Chattogram";
        case SYLHET:     return "Sylhet";
        case RAJSHAHI:   return "Rajshahi";
        case KHULNA:     return "Khulna";
        case BARISHAL:   return "Barishal";
        case RANGPUR:    return "Rangpur";
        case MYMENSINGH: return "Mymensingh";
        default:         return "Unknown";
    }
}

static const char *roadConditionToString(RoadCondition c) {
    switch (c) {
        case EXCELLENT: return "Excellent";
        case GOOD:      return "Good";
        case AVERAGE:   return "Average";
        case POOR:      return "Poor";
        default:        return "Unknown";
    }
}

static const char *vehicleTypeToString(VehicleType v) {
    switch (v) {
        case BUS:        return "Bus";
        case CAR:        return "Car";
        case MOTORCYCLE:  return "Motorcycle";
        case MICROBUS:   return "Microbus";
        default:         return "Unknown";
    }
}

static double travelTimeMinutes(const Road *r) {
    if (r->speedLimit <= 0) return 0.0;
    return (r->distanceKm / (double)r->speedLimit) * 60.0;
}

//একটা road-এর জন্য vehicle অনুযায়ী cost বের করে
static double costForRoad(const Road *r, VehicleType v) {
    switch (v) {
        case BUS:        return r->busFare;
        case CAR:        return r->carFuelCost;
        case MOTORCYCLE: return r->motorcycleCost;
        case MICROBUS:   return r->microbusCost;
        default:         return 0.0;
    }
}

//vehicle অনুযায়ী approximate mileage ধরা হয়েছে।
static double estimateFuelCost(double distanceKm, VehicleType v) {
    /* approximate mileage in km/litre and price per litre (Tk) */
    double mileage, pricePerLitre = 125.0;
    switch (v) {
        case CAR:        mileage = 12.0; break;
        case MOTORCYCLE:  mileage = 40.0; break;
        case MICROBUS:   mileage = 9.0;  break;
        default:         mileage = 4.0;  break; /* bus */
    }
    return (distanceKm / mileage) * pricePerLitre;
}

//minutes-কে সুন্দর format-এ convert করে।
static char *formatTime(double minutes, char *out, size_t outSize) {
    int totalMinutes = (int)(minutes + 0.5);
    int hours = totalMinutes / 60;
    int mins = totalMinutes % 60;
    if (hours > 0)
        snprintf(out, outSize, "%d %s %d %s", hours, hours == 1 ? "Hour" : "Hours",
                 mins, mins == 1 ? "Minute" : "Minutes");
    else
        snprintf(out, outSize, "%d %s", mins, mins == 1 ? "Minute" : "Minutes");
    return out;
}

/*Place management */

static int findPlaceIndex(const char *name) {
    for (int i = 0; i < placeCount; ++i)
        if (strcasecmp(places[i].name, name) == 0) return i;
    return -1;
}

static int addPlace(const char *name, Division div, const char *district, const char *desc,
                     const char *open_, const char *close_, int fee, const char *season,
                     double lat, double lon, const char * const nearby[], int nearbyCount) {
    if (placeCount >= MAX_PLACES) return -1;
    Place *p = &places[placeCount];
    strncpy(p->name, name, NAME_LEN - 1);
    p->division = div;
    strncpy(p->district, district, NAME_LEN - 1);
    strncpy(p->description, desc, DESC_LEN - 1);
    strncpy(p->openingTime, open_, SMALL_LEN - 1);
    strncpy(p->closingTime, close_, SMALL_LEN - 1);
    p->entryFee = fee;
    strncpy(p->bestSeason, season, SMALL_LEN - 1);
    p->lat = lat;
    p->lon = lon;
    p->nearbyCount = (nearbyCount > MAX_NEARBY) ? MAX_NEARBY : nearbyCount;
    for (int i = 0; i < p->nearbyCount; ++i)
        strncpy(p->nearby[i], nearby[i], NAME_LEN - 1);
    adjCount[placeCount] = 0;
    return placeCount++;
}

static void printPlaceDetails(const Place *p) {
    printDivider('=', 60);
    printf(BOLD CYAN "  %s" RESET "\n", p->name);
    printDivider('-', 60);
    printf("  Division        : %s\n", divisionToString(p->division));
    printf("  District        : %s\n", p->district);
    printf("  Description     : %s\n", p->description);
    printf("  Opening Time    : %s\n", p->openingTime);
    printf("  Closing Time    : %s\n", p->closingTime);
    if (p->entryFee == 0) printf("  Entry Fee       : Free\n");
    else printf("  Entry Fee       : %d Tk\n", p->entryFee);
    printf("  Best Season     : %s\n", p->bestSeason);
    printf("  Coordinates     : %.4f N, %.4f E\n", p->lat, p->lon);
    printf("  Nearby Places   : ");
    for (int i = 0; i < p->nearbyCount; ++i) {
        printf("%s", p->nearby[i]);
        if (i + 1 < p->nearbyCount) printf(", ");
    }
    printf("\n");
    printDivider('=', 60);
}

static void printPlaceSummary(const Place *p, int index) {
    printf(" %2d. " BOLD "%s" RESET "  (%s, %s)\n", index, p->name, divisionToString(p->division), p->district);
}

/*Road / graph management*/

static int addDirectedRoad(const char *roadName, int from, int to, double dist, int speed,
                            RoadCondition cond, const char *desc,
                            double bus, double car, double moto, double micro) {
    if (roadCount >= MAX_ROADS) return -1;
    Road *r = &roads[roadCount];
    strncpy(r->roadName, roadName, sizeof(r->roadName) - 1);
    r->from = from; r->to = to;
    r->distanceKm = dist; r->speedLimit = speed; r->condition = cond;
    strncpy(r->description, desc, DESC_LEN - 1);
    r->busFare = bus; r->carFuelCost = car; r->motorcycleCost = moto; r->microbusCost = micro;

    if (adjCount[from] < MAX_NEIGHBORS)
        adjIndex[from][adjCount[from]++] = roadCount;
    return roadCount++;
}

static void addRoad(const char *roadName, const char *fromName, const char *toName, double dist, int speed,
                     RoadCondition cond, const char *desc, double bus, double car, double moto, double micro) {
    int from = findPlaceIndex(fromName);
    int to = findPlaceIndex(toName);
    if (from < 0 || to < 0) { printError("addRoad: unknown place name in map data"); return; }
    addDirectedRoad(roadName, from, to, dist, speed, cond, desc, bus, car, moto, micro);
    addDirectedRoad(roadName, to, from, dist, speed, cond, desc, bus, car, moto, micro);
    ++physicalRoadCount;
}

static void printRoadDetails(const Road *r) {
    printf(BOLD YELLOW "  %s" RESET "\n", r->roadName);
    printf("  Route           : %s  <->  %s\n", places[r->from].name, places[r->to].name);
    printf("  Distance        : %.1f km\n", r->distanceKm);
    printf("  Speed Limit     : %d km/h\n", r->speedLimit);
    printf("  Travel Time     : %.0f minutes\n", travelTimeMinutes(r));
    printf("  Road Condition  : %s\n", roadConditionToString(r->condition));
    printf("  Description     : %s\n", r->description);
    printf("  Bus Fare        : %.0f Tk\n", r->busFare);
    printf("  Car Fuel Cost   : %.0f Tk\n", r->carFuelCost);
    printf("  Motorcycle Cost : %.0f Tk\n", r->motorcycleCost);
    printf("  Microbus Cost   : %.0f Tk\n", r->microbusCost);
    printThinDivider();
}

static void printFullMap(void) {
    printHeader("COMPLETE ROAD MAP");
    for (int i = 0; i < placeCount; ++i) {
        printf(BOLD GREEN "%s" RESET "\n", places[i].name);
        if (adjCount[i] == 0) {
            printf("   (no direct roads)\n");
        }
        for (int k = 0; k < adjCount[i]; ++k) {
            const Road *r = &roads[adjIndex[i][k]];
            printf("   -> %-28s via " BOLD "%s" RESET " (%.1f km)\n", places[r->to].name, r->roadName, r->distanceKm);
        }
        printThinDivider();
    }
}

/* ============================================================
   Route helpers
   ============================================================ */
static void recalcRoute(Route *route) {
    route->totalDistance = 0.0;
    route->totalTime = 0.0;
    route->totalCost = 0.0;
    for (int i = 0; i < route->roadCount; ++i) {
        const Road *r = &roads[route->roadIdx[i]];
        route->totalDistance += r->distanceKm;
        route->totalTime += travelTimeMinutes(r);
        route->totalCost += r->busFare; /* default cost basis = bus fare */
    }
}

static int routeIsEmpty(const Route *route) { return route->placeCount == 0; }

static void printRouteGoogleMapsStyle(const Route *route) {
    char timeBuf[64];
    if (routeIsEmpty(route)) { printError("No route available to display."); return; }

    printDivider('=', 60);
    printf(BOLD "FROM: " RESET CYAN "%s" RESET "\n", places[route->placeIdx[0]].name);
    printf(BOLD "TO:   " RESET CYAN "%s" RESET "\n", places[route->placeIdx[route->placeCount - 1]].name);
    printDivider('=', 60);

    printf(BOLD "Start from %s" RESET "\n", places[route->placeIdx[0]].name);
    for (int i = 0; i < route->roadCount; ++i) {
        const Road *r = &roads[route->roadIdx[i]];
        printf("   " GRAY "|" RESET "\n   " YELLOW "v" RESET "\n");
        printf("Take " BOLD "%s" RESET "  (%.1f km, %s condition)\n", r->roadName, r->distanceKm, roadConditionToString(r->condition));
        printf("   " GRAY "|" RESET "\n   " YELLOW "v" RESET "\n");
        printf("Reach " BOLD "%s" RESET "\n", places[route->placeIdx[i + 1]].name);
    }

    printDivider('=', 60);
    printf(BOLD "Total Distance   : " RESET "%.1f km\n", route->totalDistance);
    printf(BOLD "Estimated Time   : " RESET "%s\n", formatTime(route->totalTime, timeBuf, sizeof(timeBuf)));
    printf(BOLD "Total Cost (Bus) : " RESET "%.0f Tk\n", route->totalCost);
    printf(BOLD "Total Stops      : " RESET "%d places\n", route->placeCount);
    printDivider('=', 60);
}

static void printRouteSummaryLine(const Route *route, int index) {
    char timeBuf[64];
    printf(" %2d. ", index);
    for (int i = 0; i < route->placeCount; ++i) {
        printf("%s", places[route->placeIdx[i]].name);
        if (i + 1 < route->placeCount) printf(" -> ");
    }
    printf("  [%.1f km, %s, %.0f Tk]\n", route->totalDistance,
           formatTime(route->totalTime, timeBuf, sizeof(timeBuf)), route->totalCost);
}

static void serializeRouteToFile(const Route *route, FILE *f) {
    fprintf(f, "ROUTE_START\n");
    fprintf(f, "PATH: ");
    for (int i = 0; i < route->placeCount; ++i) {
        fprintf(f, "%s", places[route->placeIdx[i]].name);
        if (i + 1 < route->placeCount) fprintf(f, " | ");
    }
    fprintf(f, "\nROADS: ");
    for (int i = 0; i < route->roadCount; ++i) {
        fprintf(f, "%s", roads[route->roadIdx[i]].roadName);
        if (i + 1 < route->roadCount) fprintf(f, " | ");
    }
    fprintf(f, "\nDISTANCE_KM: %.2f\nTIME_MIN: %.2f\nCOST_TK: %.2f\nROUTE_END\n",
            route->totalDistance, route->totalTime, route->totalCost);
}

/* ============================================================
   Pathfinding algorithms
   ============================================================ */
static double edgeWeight(const Road *r, WeightMode mode, VehicleType vehicle) {
    switch (mode) {
        case WEIGHT_DISTANCE: return r->distanceKm;
        case WEIGHT_TIME:     return travelTimeMinutes(r);
        case WEIGHT_COST:     return costForRoad(r, vehicle);
        default:              return r->distanceKm;
    }
}

/* Dijkstra: O(V^2), fine for a small graph. Returns 1 on success. */
static int dijkstra(int start, int end, WeightMode mode, VehicleType vehicle, Route *out) {
    double dist[MAX_PLACES];
    int prevPlace[MAX_PLACES], prevRoad[MAX_PLACES], visited[MAX_PLACES];

    for (int i = 0; i < placeCount; ++i) {
        dist[i] = INFINITY;
        prevPlace[i] = -1;
        prevRoad[i] = -1;
        visited[i] = 0;
    }
    dist[start] = 0.0;

    for (int iter = 0; iter < placeCount; ++iter) {
        int u = -1;
        double best = INFINITY;
        for (int i = 0; i < placeCount; ++i)
            if (!visited[i] && dist[i] < best) { best = dist[i]; u = i; }
        if (u == -1) break;
        visited[u] = 1;
        if (u == end) break;

        for (int k = 0; k < adjCount[u]; ++k) {
            const Road *r = &roads[adjIndex[u][k]];
            double w = edgeWeight(r, mode, vehicle);
            if (dist[u] + w < dist[r->to]) {
                dist[r->to] = dist[u] + w;
                prevPlace[r->to] = u;
                prevRoad[r->to] = adjIndex[u][k];
            }
        }
    }

    out->placeCount = 0;
    out->roadCount = 0;
    if (!isfinite(dist[end])) return 0;

    int tmpPlaces[MAX_PLACES], tmpRoads[MAX_PLACES], n = 0;
    int cur = end;
    while (cur != start) {
        tmpPlaces[n] = cur;
        tmpRoads[n] = prevRoad[cur];
        ++n;
        cur = prevPlace[cur];
    }
    tmpPlaces[n++] = start;

    for (int i = 0; i < n; ++i) out->placeIdx[i] = tmpPlaces[n - 1 - i];
    out->placeCount = n;
    for (int i = 0; i < n - 1; ++i) out->roadIdx[i] = tmpRoads[n - 2 - i];
    out->roadCount = n - 1;
    recalcRoute(out);
    return 1;
}

static int findShortestDistance(int start, int end, Route *out) { return dijkstra(start, end, WEIGHT_DISTANCE, CAR, out); }
static int findFastestRoute(int start, int end, Route *out)     { return dijkstra(start, end, WEIGHT_TIME, CAR, out); }
static int findCheapestRoute(int start, int end, VehicleType v, Route *out) { return dijkstra(start, end, WEIGHT_COST, v, out); }

/* BFS: fewest hops */
static int findLeastStops(int start, int end, Route *out) {
    int visited[MAX_PLACES] = {0};
    int prevPlace[MAX_PLACES], prevRoad[MAX_PLACES];
    int queue[MAX_PLACES], qHead = 0, qTail = 0;

    for (int i = 0; i < placeCount; ++i) { prevPlace[i] = -1; prevRoad[i] = -1; }
    queue[qTail++] = start;
    visited[start] = 1;
    int found = 0;

    while (qHead < qTail) {
        int u = queue[qHead++];
        if (u == end) { found = 1; break; }
        for (int k = 0; k < adjCount[u]; ++k) {
            const Road *r = &roads[adjIndex[u][k]];
            if (!visited[r->to]) {
                visited[r->to] = 1;
                prevPlace[r->to] = u;
                prevRoad[r->to] = adjIndex[u][k];
                queue[qTail++] = r->to;
            }
        }
    }

    out->placeCount = 0;
    out->roadCount = 0;
    if (!found) return 0;

    int tmpPlaces[MAX_PLACES], tmpRoads[MAX_PLACES], n = 0;
    int cur = end;
    while (cur != start) {
        tmpPlaces[n] = cur;
        tmpRoads[n] = prevRoad[cur];
        ++n;
        cur = prevPlace[cur];
    }
    tmpPlaces[n++] = start;

    for (int i = 0; i < n; ++i) out->placeIdx[i] = tmpPlaces[n - 1 - i];
    out->placeCount = n;
    for (int i = 0; i < n - 1; ++i) out->roadIdx[i] = tmpRoads[n - 2 - i];
    out->roadCount = n - 1;
    recalcRoute(out);
    return 1;
}

/* DFS: all simple paths, capped at MAX_ROUTES */
static void dfsAllRoutesHelper(int current, int end, int *pathPlaces, int pathLen, int *pathRoads, int roadLen,
                                int *visited, Route *results, int *resultCount) {
    if (*resultCount >= MAX_ROUTES) return;

    if (current == end) {
        Route *r = &results[*resultCount];
        r->placeCount = pathLen;
        for (int i = 0; i < pathLen; ++i) r->placeIdx[i] = pathPlaces[i];
        r->roadCount = roadLen;
        for (int i = 0; i < roadLen; ++i) r->roadIdx[i] = pathRoads[i];
        recalcRoute(r);
        ++(*resultCount);
        return;
    }

    for (int k = 0; k < adjCount[current]; ++k) {
        const Road *r = &roads[adjIndex[current][k]];
        if (!visited[r->to]) {
            visited[r->to] = 1;
            pathPlaces[pathLen] = r->to;
            pathRoads[roadLen] = adjIndex[current][k];
            dfsAllRoutesHelper(r->to, end, pathPlaces, pathLen + 1, pathRoads, roadLen + 1, visited, results, resultCount);
            visited[r->to] = 0;
        }
    }
}

static int findAllRoutes(int start, int end, Route *results) {
    int visited[MAX_PLACES] = {0};
    int pathPlaces[MAX_PLACES], pathRoads[MAX_PLACES];
    int resultCount = 0;

    visited[start] = 1;
    pathPlaces[0] = start;
    dfsAllRoutesHelper(start, end, pathPlaces, 1, pathRoads, 0, visited, results, &resultCount);

    /* sort by total distance, ascending (small n, insertion sort) */
    for (int i = 1; i < resultCount; ++i) {
        Route key = results[i];
        int j = i - 1;
        while (j >= 0 && results[j].totalDistance > key.totalDistance) {
            results[j + 1] = results[j];
            --j;
        }
        results[j + 1] = key;
    }
    return resultCount;
}

/* ============================================================
   File persistence
   ============================================================ */
static int routesFileExists(void) {
    FILE *f = fopen(ROUTES_FILE, "r");
    if (!f) return 0;
    fclose(f);
    return 1;
}

static int saveRouteToFile(const Route *route, const char *label) {
    FILE *f = fopen(ROUTES_FILE, "a");
    if (!f) return 0;

    time_t now = time(NULL);
    char timeBuf[64];
    strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", localtime(&now));

    fprintf(f, "LABEL: %s\nSAVED_AT: %s\n", label, timeBuf);
    serializeRouteToFile(route, f);
    fprintf(f, "----------------------------------------\n");
    fclose(f);
    return 1;
}

static void loadAndPrintSavedRoutes(void) {
    FILE *f = fopen(ROUTES_FILE, "r");
    if (!f) { printInfo("No saved routes found. Use option 13 to save a route first."); return; }

    char line[512];
    int idx = 0, any = 0, atBlockStart = 1;
    while (fgets(line, sizeof(line), f)) {
        if (strncmp(line, "----------------------------------------", 40) == 0) {
            atBlockStart = 1;
            continue;
        }
        if (atBlockStart) {
            ++idx;
            printThinDivider();
            printf(BOLD "Saved Route #%d" RESET "\n", idx);
            any = 1;
            atBlockStart = 0;
        }
        fputs(line, stdout);
    }
    fclose(f);

    if (!any) printInfo("routes.txt is empty. No saved routes to display.");
    else printThinDivider();
}

/* ============================================================
   Statistics
   ============================================================ */
static void printStatistics(void) {
    printHeader("ROUTE NETWORK STATISTICS");

    if (placeCount == 0) { printError("The map is empty. No statistics available."); return; }

    double totalDistance = 0.0, longestDistance = -1.0, shortestDistance = INFINITY;
    int longestRoadIdx = -1, shortestRoadIdx = -1, edgeSamples = 0;
    int mostConnectedPlace = 0, mostConnections = 0;

    for (int i = 0; i < placeCount; ++i) {
        if (adjCount[i] > mostConnections) { mostConnections = adjCount[i]; mostConnectedPlace = i; }
        for (int k = 0; k < adjCount[i]; ++k) {
            const Road *r = &roads[adjIndex[i][k]];
            totalDistance += r->distanceKm;
            ++edgeSamples;
            if (r->distanceKm > longestDistance) { longestDistance = r->distanceKm; longestRoadIdx = adjIndex[i][k]; }
            if (r->distanceKm < shortestDistance) { shortestDistance = r->distanceKm; shortestRoadIdx = adjIndex[i][k]; }
        }
    }

    double averageDistance = (edgeSamples > 0) ? (totalDistance / edgeSamples) : 0.0;

    printf(BOLD "Total Tourist Places   : " RESET "%d\n", placeCount);
    printf(BOLD "Total Roads            : " RESET "%d\n", physicalRoadCount);
    printf(BOLD "Average Road Distance  : " RESET "%.1f km\n", averageDistance);
    if (longestRoadIdx >= 0) {
        const Road *r = &roads[longestRoadIdx];
        printf(BOLD "Longest Road           : " RESET "%s (%s <-> %s, %.1f km)\n",
               r->roadName, places[r->from].name, places[r->to].name, r->distanceKm);
    }
    if (shortestRoadIdx >= 0) {
        const Road *r = &roads[shortestRoadIdx];
        printf(BOLD "Shortest Road          : " RESET "%s (%s <-> %s, %.1f km)\n",
               r->roadName, places[r->from].name, places[r->to].name, r->distanceKm);
    }
    printf(BOLD "Most Connected Place   : " RESET "%s (%d direct roads)\n", places[mostConnectedPlace].name, mostConnections);

    printDivider('=', 60);
    printf(BOLD "Places per Division:" RESET "\n");
    int divisionCount[DIVISION_COUNT] = {0};
    for (int i = 0; i < placeCount; ++i) divisionCount[places[i].division]++;
    for (int d = 0; d < DIVISION_COUNT; ++d)
        if (divisionCount[d] > 0)
            printf("   %-15s: %d place(s)\n", divisionToString((Division)d), divisionCount[d]);
    printDivider('=', 60);
}

/* ============================================================
   Map data
   ============================================================ */
/* ---- static data tables: the raw map data lives here, as plain structs,
   separate from the loading logic that walks the tables below. ---- */
typedef struct {
    const char *name;
    Division division;
    const char *district;
    const char *description;
    const char *openingTime;
    const char *closingTime;
    int entryFee;
    const char *bestSeason;
    double lat, lon;
    const char *nearby[MAX_NEARBY];
    int nearbyCount;
} PlaceData;

typedef struct {
    const char *roadName;
    const char *from;
    const char *to;
    double distanceKm;
    int speedLimit;
    RoadCondition condition;
    const char *description;
    double busFare, carFuelCost, motorcycleCost, microbusCost;
} RoadData;

static const PlaceData placeTable[] = {
    { "Ahsan Manzil", DHAKA, "Dhaka",
      "The Pink Palace, former residence of the Nawab of Dhaka, on the bank of the Buriganga River.",
      "09:00 AM", "05:00 PM", 20, "November - February", 23.7075, 90.4058,
      { "Lalbagh Fort", "Buriganga River", "Sadarghat" }, 3 },

    { "Lalbagh Fort", DHAKA, "Dhaka",
      "An incomplete 17th-century Mughal fort complex with gardens, a mosque and a tomb.",
      "10:00 AM", "05:30 PM", 20, "October - March", 23.7189, 90.3883,
      { "Ahsan Manzil", "Dhakeshwari Temple" }, 2 },

    { "Bhawal National Park", DHAKA, "Gazipur",
      "A dense sal-forest national park popular for picnics and short nature trails.",
      "08:00 AM", "06:00 PM", 10, "November - February", 24.0000, 90.4000,
      { "Bhawal Rajbari", "Sal Forest Trails" }, 2 },

    { "Patenga Beach", CHATTOGRAM, "Chattogram",
      "A popular sea beach at the mouth of the Karnaphuli River, known for its sunsets.",
      "06:00 AM", "09:00 PM", 0, "November - February", 22.2352, 91.7914,
      { "Karnaphuli River Mouth", "Naval Base" }, 2 },

    { "Cox's Bazar", CHATTOGRAM, "Cox's Bazar",
      "Home to the world's longest unbroken natural sea beach, stretching over 120 km.",
      "24 Hours", "24 Hours", 0, "November - February", 21.4272, 92.0058,
      { "Himchari National Park", "Inani Beach" }, 2 },

    { "Saint Martin", CHATTOGRAM, "Cox's Bazar",
      "Bangladesh's only coral island, reachable by sea, famous for clear water and coconut trees.",
      "24 Hours", "24 Hours", 0, "November - February", 20.6284, 92.3220,
      { "Chera Dwip", "Coral Reefs" }, 2 },

    { "Jaflong", SYLHET, "Sylhet",
      "A scenic hill-and-river frontier spot where the Piyain River meets the Khasi Hills.",
      "07:00 AM", "06:00 PM", 0, "October - March", 25.1699, 92.0129,
      { "Zaflong Stone Collection Point", "Khasia Village" }, 2 },

    { "Ratargul", SYLHET, "Sylhet",
      "The only swamp forest in Bangladesh, navigable by small boat during the monsoon.",
      "08:00 AM", "05:00 PM", 20, "June - September", 25.0186, 91.9781,
      { "Gowain River", "Swamp Forest Trails" }, 2 },

    { "Sreemangal", SYLHET, "Moulvibazar",
      "The tea capital of Bangladesh, surrounded by rolling tea estates and pineapple gardens.",
      "24 Hours", "24 Hours", 0, "September - March", 24.3065, 91.7296,
      { "Lawachara National Park", "Tea Estates" }, 2 },

    { "Puthia Rajbari", RAJSHAHI, "Rajshahi",
      "A cluster of ornate 19th-century Hindu temples and a zamindar palace complex.",
      "09:00 AM", "05:00 PM", 20, "October - March", 24.3808, 88.9758,
      { "Shiva Temple", "Govinda Temple" }, 2 },

    { "Paharpur", RAJSHAHI, "Naogaon",
      "Somapura Mahavihara, a UNESCO World Heritage 8th-century Buddhist monastery ruin.",
      "09:00 AM", "05:00 PM", 20, "October - March", 25.0311, 88.9767,
      { "Somapura Mahavihara Museum" }, 1 },

    { "Sundarbans", KHULNA, "Khulna",
      "The largest mangrove forest on Earth and home of the Royal Bengal Tiger.",
      "06:00 AM", "05:00 PM", 60, "November - February", 22.0000, 89.5000,
      { "Karamjal Wildlife Centre", "Kotka Beach" }, 2 },

    { "Kuakata", BARISHAL, "Patuakhali",
      "The 'Daughter of the Sea', a rare beach where both sunrise and sunset can be seen.",
      "24 Hours", "24 Hours", 0, "November - February", 21.8189, 90.1197,
      { "Kuakata Beach", "Rakhine Buddhist Temple" }, 2 },

    { "Kantajew Temple", RANGPUR, "Dinajpur",
      "An 18th-century terracotta Hindu temple famed for its intricate carved brick artwork.",
      "09:00 AM", "05:00 PM", 20, "October - March", 25.7647, 88.8981,
      { "Dinajpur Rajbari", "Ramsagar Lake" }, 2 },
};
static const int placeTableCount = (int)(sizeof(placeTable) / sizeof(placeTable[0]));

static const RoadData roadTable[] = {
    { "Buriganga River Road", "Ahsan Manzil", "Lalbagh Fort",
      3.0, 30, GOOD, "Narrow old-town street, riverside, moderate rickshaw traffic.",
      10, 30, 15, 25 },

    { "Dhaka-Mymensingh Highway N3", "Ahsan Manzil", "Bhawal National Park",
      45.0, 70, EXCELLENT, "Four-lane highway, smooth surface, light traffic outside rush hour.",
      100, 280, 90, 220 },

    { "Chattogram-Cox's Bazar Marine Drive", "Patenga Beach", "Cox's Bazar",
      150.0, 70, EXCELLENT, "Scenic coastal marine drive, smooth asphalt, stunning sea views.",
      280, 1050, 400, 850 },

    { "Teknaf-Saint Martin Sea Route AH41", "Cox's Bazar", "Saint Martin",
      80.0, 25, AVERAGE, "Sea route by passenger ship via Teknaf, seasonal (Nov-Mar), waters can be rough.",
      900, 900, 900, 900 },

    { "Rajshahi-Naogaon Road R203", "Puthia Rajbari", "Paharpur",
      55.0, 60, AVERAGE, "Regional road with some pothole sections near Naogaon town.",
      90, 320, 130, 260 },

    { "Dhaka-Chattogram Highway N1", "Patenga Beach", "Bhawal National Park",
      250.0, 80, EXCELLENT, "Major national highway, four-lane in most sections, moderate truck traffic.",
      473, 1705, 663, 1420 },

    { "Sylhet-Moulvibazar Road N208", "Sreemangal", "Ratargul",
      60.0, 60, GOOD, "Well-paved road through tea-estate country, gentle curves.",
      110, 380, 150, 300 },

    { "Dhaka-Sylhet Highway N2", "Sreemangal", "Bhawal National Park",
      150.0, 75, GOOD, "Busy national highway, under continuous widening work, moderate traffic.",
      278, 1044, 407, 884 },

    { "Khulna-Barishal Coastal Highway N807", "Sundarbans", "Kuakata",
      130.0, 60, AVERAGE, "Coastal highway with a couple of ferry crossings over southern rivers.",
      250, 900, 340, 750 },

    { "Khulna-Rajshahi Regional Highway", "Sundarbans", "Puthia Rajbari",
      220.0, 80, EXCELLENT, "Modern regional highway linking the southwest to Rajshahi division.",
      397, 1515, 591, 1262 },

    { "Sylhet-Jaflong Road N204", "Ratargul", "Jaflong",
      45.0, 55, AVERAGE, "Winding rural road along the Piyain river valley, hilly terrain.",
      80, 290, 110, 230 },

    { "Dhaka-Rajshahi Highway N6", "Bhawal National Park", "Puthia Rajbari",
      220.0, 75, GOOD, "Two-to-four lane highway through Pabna, generally smooth with some repair sections.",
      413, 1504, 584, 1246 },

    { "Rajshahi-Rangpur Highway N509", "Puthia Rajbari", "Kantajew Temple",
      180.0, 65, GOOD, "Regional highway connecting the northwest divisions, mostly smooth two-lane road.",
      340, 1250, 480, 1050 },
};
static const int roadTableCount = (int)(sizeof(roadTable) / sizeof(roadTable[0]));

static void loadPlaces(void) {
    for (int i = 0; i < placeTableCount; ++i) {
        const PlaceData *d = &placeTable[i];
        addPlace(d->name, d->division, d->district, d->description,
                 d->openingTime, d->closingTime, d->entryFee, d->bestSeason,
                 d->lat, d->lon, d->nearby, d->nearbyCount);
    }
}

static void loadRoads(void) {
    for (int i = 0; i < roadTableCount; ++i) {
        const RoadData *d = &roadTable[i];
        addRoad(d->roadName, d->from, d->to, d->distanceKm, d->speedLimit, d->condition,
                d->description, d->busFare, d->carFuelCost, d->motorcycleCost, d->microbusCost);
    }
}

static void loadAll(void) {
    loadPlaces();
    loadRoads();
}

/* ============================================================
   Menu / input helpers
   ============================================================ */
static void showMainMenu(void) {
    printDivider('=', 60);
    printf(BOLD CYAN "                   MAIN MENU" RESET "\n");
    printDivider('=', 60);
    printf(
        "  1. View Tourist Places        10. Estimate Travel Cost\n"
        "  2. View Complete Map          11. Estimate Fuel Cost\n"
        "  3. Search Place               12. Print Route\n"
        "  4. Route Between Two Places   13. Save Route\n"
        "  5. All Possible Routes        14. Load Route\n"
        "  6. Shortest Route             15. Statistics\n"
        "  7. Cheapest Route             16. Help\n"
        "  8. Fastest Route              17. Exit\n"
        "  9. View Road Details\n");
    printDivider('=', 60);
    printf("Enter your choice (1-17): ");
}

static int readMenuChoice(void) {
    int choice;
    while (scanf("%d", &choice) != 1) {
        if (feof(stdin)) return 17;
        int c; while ((c = getchar()) != '\n' && c != EOF) {}
        printError("Invalid input. Please enter a number between 1 and 17.");
        printf("Enter your choice (1-17): ");
    }
    int c; while ((c = getchar()) != '\n' && c != EOF) {}
    return choice;
}

static char *readLine(char *buf, size_t bufSize) {
    if (!fgets(buf, (int)bufSize, stdin)) { buf[0] = '\0'; return buf; }
    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') buf[len - 1] = '\0';
    return buf;
}

static char *readPlaceName(const char *prompt, char *buf, size_t bufSize) {
    printf("%s", prompt);
    return readLine(buf, bufSize);
}

static VehicleType readVehicleChoice(void) {
    printf("Select Vehicle:\n  1. Bus\n  2. Car\n  3. Motorcycle\n  4. Microbus\nEnter choice (1-4): ");
    int choice;
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
        if (feof(stdin)) return BUS;
        int c; while ((c = getchar()) != '\n' && c != EOF) {}
        printError("Invalid choice. Enter a number between 1 and 4.");
        printf("Enter choice (1-4): ");
    }
    int c; while ((c = getchar()) != '\n' && c != EOF) {}
    switch (choice) {
        case 1: return BUS;
        case 2: return CAR;
        case 3: return MOTORCYCLE;
        default: return MICROBUS;
    }
}

static int validateSourceDestination(const char *from, const char *to, int *fromIdx, int *toIdx) {
    *fromIdx = findPlaceIndex(from);
    *toIdx = findPlaceIndex(to);
    if (*fromIdx < 0) {
        char msg[256]; snprintf(msg, sizeof(msg), "Unknown place: \"%s\". Use option 3 to search for valid names.", from);
        printError(msg);
        return 0;
    }
    if (*toIdx < 0) {
        char msg[256]; snprintf(msg, sizeof(msg), "Unknown place: \"%s\". Use option 3 to search for valid names.", to);
        printError(msg);
        return 0;
    }
    if (*fromIdx == *toIdx) {
        printError("Source and destination cannot be the same place.");
        return 0;
    }
    return 1;
}

/* ============================================================
   Menu option handlers
   ============================================================ */
static void optionViewTouristPlaces(void) {
    printHeader("TOURIST PLACES");
    for (int i = 0; i < placeCount; ++i) printPlaceSummary(&places[i], i + 1);
    printf("\nTotal: %d places across %d divisions.\n", placeCount, DIVISION_COUNT);
}

static void optionViewCompleteMap(void) { printFullMap(); }

static void optionSearchPlace(void) {
    printHeader("SEARCH TOURIST PLACE");
    char query[NAME_LEN];
    readPlaceName("Enter place name to search: ", query, sizeof(query));
    int idx = findPlaceIndex(query);
    if (idx < 0) {
        char msg[256]; snprintf(msg, sizeof(msg), "No place found matching \"%s\".", query);
        printError(msg);
        return;
    }
    printPlaceDetails(&places[idx]);
}

static void optionRouteBetweenTwoPlaces(void) {
    printHeader("ROUTE BETWEEN TWO PLACES");
    char from[NAME_LEN], to[NAME_LEN];
    readPlaceName("Enter starting place: ", from, sizeof(from));
    readPlaceName("Enter destination place: ", to, sizeof(to));
    int fi, ti;
    if (!validateSourceDestination(from, to, &fi, &ti)) return;

    Route route;
    if (!findShortestDistance(fi, ti, &route)) {
        char msg[256]; snprintf(msg, sizeof(msg), "No route exists between \"%s\" and \"%s\".", from, to);
        printError(msg);
        return;
    }
    printRouteGoogleMapsStyle(&route);
}

static void optionAllPossibleRoutes(void) {
    printHeader("ALL POSSIBLE ROUTES (DFS)");
    char from[NAME_LEN], to[NAME_LEN];
    readPlaceName("Enter starting place: ", from, sizeof(from));
    readPlaceName("Enter destination place: ", to, sizeof(to));
    int fi, ti;
    if (!validateSourceDestination(from, to, &fi, &ti)) return;

    Route routes[MAX_ROUTES];
    int count = findAllRoutes(fi, ti, routes);
    if (count == 0) {
        char msg[256]; snprintf(msg, sizeof(msg), "No route exists between \"%s\" and \"%s\".", from, to);
        printError(msg);
        return;
    }
    printf("\nFound %d possible route(s):\n\n", count);
    for (int i = 0; i < count; ++i) printRouteSummaryLine(&routes[i], i + 1);
}

static void optionShortestRoute(void) {
    printHeader("SHORTEST ROUTE (DIJKSTRA - DISTANCE)");
    char from[NAME_LEN], to[NAME_LEN];
    readPlaceName("Enter starting place: ", from, sizeof(from));
    readPlaceName("Enter destination place: ", to, sizeof(to));
    int fi, ti;
    if (!validateSourceDestination(from, to, &fi, &ti)) return;

    Route route;
    if (!findShortestDistance(fi, ti, &route)) {
        char msg[256]; snprintf(msg, sizeof(msg), "No route exists between \"%s\" and \"%s\".", from, to);
        printError(msg);
        return;
    }
    printRouteGoogleMapsStyle(&route);
}

static void optionCheapestRoute(void) {
    printHeader("CHEAPEST ROUTE (DIJKSTRA - COST)");
    char from[NAME_LEN], to[NAME_LEN];
    readPlaceName("Enter starting place: ", from, sizeof(from));
    readPlaceName("Enter destination place: ", to, sizeof(to));
    int fi, ti;
    if (!validateSourceDestination(from, to, &fi, &ti)) return;
    VehicleType vehicle = readVehicleChoice();

    Route route;
    if (!findCheapestRoute(fi, ti, vehicle, &route)) {
        char msg[256]; snprintf(msg, sizeof(msg), "No route exists between \"%s\" and \"%s\".", from, to);
        printError(msg);
        return;
    }
    printf("\nVehicle: %s\n", vehicleTypeToString(vehicle));
    printRouteGoogleMapsStyle(&route);
}

static void optionFastestRoute(void) {
    printHeader("FASTEST ROUTE (DIJKSTRA - TIME)");
    char from[NAME_LEN], to[NAME_LEN];
    readPlaceName("Enter starting place: ", from, sizeof(from));
    readPlaceName("Enter destination place: ", to, sizeof(to));
    int fi, ti;
    if (!validateSourceDestination(from, to, &fi, &ti)) return;

    Route route;
    if (!findFastestRoute(fi, ti, &route)) {
        char msg[256]; snprintf(msg, sizeof(msg), "No route exists between \"%s\" and \"%s\".", from, to);
        printError(msg);
        return;
    }
    printRouteGoogleMapsStyle(&route);
}

static void optionViewRoadDetails(void) {
    printHeader("ROAD DETAILS");
    char place[NAME_LEN];
    readPlaceName("Enter a place to view its connecting roads: ", place, sizeof(place));
    int idx = findPlaceIndex(place);
    if (idx < 0) {
        char msg[256]; snprintf(msg, sizeof(msg), "Unknown place: \"%s\".", place);
        printError(msg);
        return;
    }
    if (adjCount[idx] == 0) {
        char msg[256]; snprintf(msg, sizeof(msg), "No roads connect to \"%s\".", places[idx].name);
        printInfo(msg);
        return;
    }
    for (int k = 0; k < adjCount[idx]; ++k) printRoadDetails(&roads[adjIndex[idx][k]]);
}

static void optionEstimateTravelCost(void) {
    printHeader("ESTIMATE TRAVEL COST");
    char from[NAME_LEN], to[NAME_LEN];
    readPlaceName("Enter starting place: ", from, sizeof(from));
    readPlaceName("Enter destination place: ", to, sizeof(to));
    int fi, ti;
    if (!validateSourceDestination(from, to, &fi, &ti)) return;
    VehicleType vehicle = readVehicleChoice();

    Route route;
    if (!findShortestDistance(fi, ti, &route)) {
        char msg[256]; snprintf(msg, sizeof(msg), "No route exists between \"%s\" and \"%s\".", from, to);
        printError(msg);
        return;
    }
    double cost = 0.0;
    for (int i = 0; i < route.roadCount; ++i) cost += costForRoad(&roads[route.roadIdx[i]], vehicle);
    printf("\nVehicle       : %s\n", vehicleTypeToString(vehicle));
    printf("Total Distance: %.1f km\n", route.totalDistance);
    printf("Estimated Cost: %.0f Tk\n", cost);
}

static void optionEstimateFuelCost(void) {
    printHeader("ESTIMATE FUEL COST");
    char from[NAME_LEN], to[NAME_LEN];
    readPlaceName("Enter starting place: ", from, sizeof(from));
    readPlaceName("Enter destination place: ", to, sizeof(to));
    int fi, ti;
    if (!validateSourceDestination(from, to, &fi, &ti)) return;
    VehicleType vehicle = readVehicleChoice();

    Route route;
    if (!findShortestDistance(fi, ti, &route)) {
        char msg[256]; snprintf(msg, sizeof(msg), "No route exists between \"%s\" and \"%s\".", from, to);
        printError(msg);
        return;
    }
    double fuelCost = estimateFuelCost(route.totalDistance, vehicle);
    printf("\nVehicle            : %s\n", vehicleTypeToString(vehicle));
    printf("Total Distance     : %.1f km\n", route.totalDistance);
    printf("Estimated Fuel Cost: %.0f Tk\n", fuelCost);
}

static void optionPrintRoute(void) {
    printHeader("PRINT ROUTE");
    char from[NAME_LEN], to[NAME_LEN];
    readPlaceName("Enter starting place: ", from, sizeof(from));
    readPlaceName("Enter destination place: ", to, sizeof(to));
    int fi, ti;
    if (!validateSourceDestination(from, to, &fi, &ti)) return;

    Route route;
    if (!findShortestDistance(fi, ti, &route)) {
        char msg[256]; snprintf(msg, sizeof(msg), "No route exists between \"%s\" and \"%s\".", from, to);
        printError(msg);
        return;
    }
    printRouteGoogleMapsStyle(&route);
}

static void optionSaveRoute(void) {
    printHeader("SAVE ROUTE");
    char from[NAME_LEN], to[NAME_LEN];
    readPlaceName("Enter starting place: ", from, sizeof(from));
    readPlaceName("Enter destination place: ", to, sizeof(to));
    int fi, ti;
    if (!validateSourceDestination(from, to, &fi, &ti)) return;

    Route route;
    if (!findShortestDistance(fi, ti, &route)) {
        char msg[256]; snprintf(msg, sizeof(msg), "No route exists between \"%s\" and \"%s\".", from, to);
        printError(msg);
        return;
    }
    printRouteGoogleMapsStyle(&route);

    char label[NAME_LEN];
    readPlaceName("\nEnter a label for this saved route: ", label, sizeof(label));
    if (saveRouteToFile(&route, label)) printSuccess("Route saved to routes.txt");
    else printError("Failed to save route. Check file permissions.");
}

static void optionLoadRoute(void) {
    printHeader("LOAD SAVED ROUTES");
    if (!routesFileExists()) { printInfo("No saved routes found. Use option 13 to save a route first."); return; }
    loadAndPrintSavedRoutes();
}

static void optionShowStatistics(void) { printStatistics(); }

static void optionShowHelp(void) {
    printHeader("HELP");
    printf(
        "  - Place names are matched case-insensitively (e.g. \"kuakata\" = \"Kuakata\").\n"
        "  - Use option 1 or 3 to see valid place names before requesting a route.\n"
        "  - Option 5 (All Possible Routes) uses DFS and lists every simple path found.\n"
        "  - Option 6 (Shortest Route) uses Dijkstra minimizing total distance.\n"
        "  - Option 7 (Cheapest Route) uses Dijkstra minimizing cost for your chosen vehicle.\n"
        "  - Option 8 (Fastest Route) uses Dijkstra minimizing total travel time.\n"
        "  - BFS (least stops) is used internally when hop-count matters more than distance.\n"
        "  - Saved routes are appended to routes.txt and can be reviewed with option 14.\n"
        "  - Source and destination cannot be the same place.\n");
}

/* ============================================================
   Menu loop
   ============================================================ */
static void runMenu(void) {
    if (placeCount == 0) { printError("The map is empty. The application cannot continue."); return; }

    int running = 1;
    while (running) {
        showMainMenu();
        int choice = readMenuChoice();

        switch (choice) {
            case 1:  optionViewTouristPlaces(); break;
            case 2:  optionViewCompleteMap(); break;
            case 3:  optionSearchPlace(); break;
            case 4:  optionRouteBetweenTwoPlaces(); break;
            case 5:  optionAllPossibleRoutes(); break;
            case 6:  optionShortestRoute(); break;
            case 7:  optionCheapestRoute(); break;
            case 8:  optionFastestRoute(); break;
            case 9:  optionViewRoadDetails(); break;
            case 10: optionEstimateTravelCost(); break;
            case 11: optionEstimateFuelCost(); break;
            case 12: optionPrintRoute(); break;
            case 13: optionSaveRoute(); break;
            case 14: optionLoadRoute(); break;
            case 15: optionShowStatistics(); break;
            case 16: optionShowHelp(); break;
            case 17:
                printSuccess("Thank you for using Smart Route Planner. Safe travels!");
                running = 0;
                break;
            default:
                printError("Invalid menu option. Please choose a number between 1 and 17.");
        }

        if (running) pauseConsole();
    }
}

int main(void) {
    (void)findLeastStops; /* available internally (BFS, least-stops); see Help option */
    loadAll();
    printWelcomeBanner();
    runMenu();
    return 0;
}
