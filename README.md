# MagnonSearch

[![MagnonSearch](magnonsearch.jpg)](https://github.com/eightomic/magnonsearch)

MagnonSearch (as an [open-source](LICENSE) product of [Eightomic](https://eightomic.com)) is the evolved pattern search that has low-footprint implementation (efficient memory usage and small code size), no division/modulus/multiplication operators, no naive worst-case traps, no pattern preprocessing and ultra-fast speed (relative to the aforementioned constraints).

Each mention of MagnonSearch refers to both of the following variants individually (`magnonsearch_first` and `magnonsearch_last`) implemented in C.

The integral type of each element in `haystack` must match the integral type of each element in `jump_character_a`, `jump_character_b`, `needle` and `needle_tail_character`.

[magnonsearch.c](magnonsearch.c)

Each of the following speed benchmark results (with `gcc` from an AMD A4-9120C) log the fastest process execution speed (in milliseconds) among several repetitions of searching varying rounds of varying `haystack_length` pseudorandom `haystack` elements and varying `needle_length` pseudorandom `needle` elements in a blocking loop.

The `magnonsearch_first` function searches in a `haystack` array (of `haystack_length` elements) for the first occurrence (left-to-right) of a `needle` array (of `needle_length` elements). When `needle` is found, `1` is returned and the index position of the first element in `needle` is assigned as the value pointed to by `position`. When `needle` isn't found, `0` is returned.

```
haystack_length   needle_length   Rounds   Unique       Elapsed                Elapsed
                                           Characters   (magnonsearch_first)   (kmp_search_first)

10                2               1m       2            170ms                  191ms
10                2               1m       4            180ms                  220ms
10                2               1m       8            159ms                  205ms
10                2               1m       256          135ms                  177ms
10                5               1m       2            281ms                  332ms
10                5               1m       4            206ms                  265ms
10                5               1m       8            170ms                  225ms
10                5               1m       256          148ms                  195ms
50                10              100k     2            141ms                  147ms
50                10              100k     4            95ms                   118ms
50                10              100k     8            79ms                   101ms
50                10              100k     256          69ms                   86ms
50                25              100k     2            125ms                  160ms
50                25              100k     4            95ms                   128ms
50                25              100k     8            84ms                   110ms
50                25              100k     256          76ms                   96ms
1k                50              10k      2            263ms                  275ms
1k                50              10k      4            176ms                  222ms
1k                50              10k      8            140ms                  182ms
1k                50              10k      256          115ms                  152ms
1k                100             10k      2            256ms                  282ms
1k                100             10k      4            177ms                  224ms
1k                100             10k      8            143ms                  185ms
1k                100             10k      256          117ms                  155ms
100k              1k              100      2            252ms                  273ms
100k              1k              100      4            179ms                  226ms
100k              1k              100      8            145ms                  187ms
100k              1k              100      256          122ms                  156ms
100k              5k              100      2            249ms                  273ms
100k              5k              100      4            183ms                  230ms
100k              5k              100      8            147ms                  190ms
100k              5k              100      256          121ms                  160ms
```

`magnonsearch_last` isn't ready to publish yet.
