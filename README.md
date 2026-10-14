# MagnonSearch

[![MagnonSearch](magnonsearch.jpg)](https://github.com/eightomic/magnonsearch)

MagnonSearch (as a proprietary, source-available product of [Eightomic](https://eightomic.com)) is the fast efficient string search that has low-footprint implementation (efficient memory usage and small code size), no division/modulus/multiplication operators, no pattern preprocessing and ultra-fast speed (relative to the aforementioned constraints).

Each mention of MagnonSearch refers to both of the following variants individually (`magnonsearch_first` and `magnonsearch_last`) implemented in C.

[magnonsearch.c](magnonsearch.c)

The `magnonsearch_first` function searches in a `haystack` array (of `haystack_length` elements) for the first occurrence (left-to-right) of a `needle` array (of `needle_length` elements). When `needle` is found, `1` is returned and the index position of the first element in `needle` is assigned as the value pointed to by `position`. When `needle` isn't found, `0` is returned. The integral type of each element in `haystack` must match the integral type of each element in `needle`.

`magnonsearch_last` isn't ready to publish yet.
