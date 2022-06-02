U - Understand:
Problem: Design a C++ class template that:
1) Represents a series of a numeric type (either an integer and/or a double).
2) A typical data object contains lots of duplicates.
3) A typical data object has no limit to the amount of unique data elements.
4) Has minimal storage requirements.
5) Supports O(1) access to statistical data members: mean, standard deviation, min, max.
This requires a call to calculation method upon each update operation.
6) Must support the following methods:
- calculate_mean: calculate mean of data series, update data member for mean statistic
- calculate_SD: private; calculate standard deviation of data series, update data member for standard deviation statistic
- calculate_min: private; calculate min of data series, update data member for min statistic
- calculate_max: private; calculate max of data series, update data member for max statistic
- get_ mean: returns the mean value of the current entire data set, must be O(1)
- get_SD: returns the standard deviation  of the current entire data set, must be O(1)
- get_min: returns the minimum data item in the current entire data set, must be O(1)
- append: append new data; call methods to update statistic data members
- removem: (remove duplicates) remove m instances of a given data element only if m is less than the current amount of duplicates n; call methods to update statistic data members
- empty: delete all data; call methods to update statistic data members
- feed: append from any standard C++ container that supports iteration; call methods to update statistic data members
- search: fastest possible search method for the data structure. Must return the location of the first occurrence and the number of occurrences.
- overloaded array index operator []: access each unique element through an index
- length_unique: number of unique elements in your data object
- length_total: total number of elements in your data object
- unique_set: return all the unique elements as an std::set
7) Container within class must be one of the linear structures included in the code provided in Canvas: AList, AQueue, AStack, etc.
8) Two constructors:
- default: empty data object
- create by feeding in data items from any standard C++ container

Input considerations: 
- feed method must append data elements from any standard C++ container
- simple_stat class container only needs to store int or double


M - Match: 
- AList seems to be most suitable container
- using template T for data member and type for stat data members

P - Plan:

I - Implement:

R - Review:

E - Evaluate:


// From the software distribution accompanying the textbook

// "A Practical Introduction to Data Structures and Algorithm Analysis,

// Third Edition (C++)" by Clifford A. Shaffer.

// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer."
