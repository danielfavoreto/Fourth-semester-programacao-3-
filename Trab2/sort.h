#ifndef SORT_H_
#define SORT_H_
#include "map_pessoas.h"
#include "map_generos.h"
#include "serie.h"
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <locale>
#include <map>
#include <vector>
#include <sstream>
#include <utility>
#include <cstdint>
#include <time.h>  
#include <algorithm>

using namespace std;

bool sort_map_names(const map_pessoas& a ,const map_pessoas& b);
bool sort_cont (const map_generos& a, const map_generos& b);
bool sort_names (string a, string b);
bool sort_names_serie (serie* a, serie* b);
vector<serie*> organiza_series (map<int,midia*> midias);
bool comparator_midia_tipo(midia* a, midia* b);
vector<string> split(string str, char delimiter);
#endif
