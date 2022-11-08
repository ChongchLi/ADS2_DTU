#pragma once
#ifndef _ford_fulkerson_h
#define _ford_fulkerson_h

#include <cstdint>

int max_flow(uint16_t** res_graph, uint16_t** graph, int n, int start, int end);

#endif