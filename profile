Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  us/call  us/call  name    
 91.48      5.03     5.03    17381   289.47   289.47  DrawTiles
  4.00      5.25     0.22 64709515     0.00     0.00  GetCollider
  4.00      5.47     0.22    34762     6.33    12.66  CollisionWithTile
  0.55      5.50     0.03    17381     1.73     1.73  DrawEntity
  0.00      5.50     0.00   488278     0.00     0.00  SetTile
  0.00      5.50     0.00    17382     0.00     0.00  GetCameraBounds
  0.00      5.50     0.00    17381     0.00    25.32  UpdateEntity
  0.00      5.50     0.00     1252     0.00     0.00  _fnlGradCoord2D
  0.00      5.50     0.00     1252     0.00     0.00  _fnlHash2D
  0.00      5.50     0.00     1024     0.00     0.00  _fnlFastFloor
  0.00      5.50     0.00      512     0.00     0.00  _fnlGenNoiseSingle2D
  0.00      5.50     0.00      512     0.00     0.00  _fnlSingleSimplex2D
  0.00      5.50     0.00      512     0.00     0.00  _fnlTransformNoiseCoordinate2D
  0.00      5.50     0.00      512     0.00     0.00  fnlGetNoise2D
  0.00      5.50     0.00        2     0.00     0.00  CreateTileType
  0.00      5.50     0.00        1     0.00     0.00  GenerateWorld
  0.00      5.50     0.00        1     0.00     0.00  RefreshEdgeBuffer
  0.00      5.50     0.00        1     0.00     0.00  fnlCreateState

 %         the percentage of the total running time of the
time       program used by this function.

cumulative a running sum of the number of seconds accounted
 seconds   for by this function and those listed above it.

 self      the number of seconds accounted for by this
seconds    function alone.  This is the major sort for this
           listing.

calls      the number of times this function was invoked, if
           this function is profiled, else blank.

 self      the average number of milliseconds spent in this
ms/call    function per call, if this function is profiled,
	   else blank.

 total     the average number of milliseconds spent in this
ms/call    function and its descendents per call, if this
	   function is profiled, else blank.

name       the name of the function.  This is the minor sort
           for this listing. The index shows the location of
	   the function in the gprof listing. If the index is
	   in parenthesis it shows where it would appear in
	   the gprof listing if it were to be printed.

Copyright (C) 2012-2023 Free Software Foundation, Inc.

Copying and distribution of this file, with or without modification,
are permitted in any medium without royalty provided the copyright
notice and this notice are preserved.

		     Call graph (explanation follows)


granularity: each sample hit covers 2 byte(s) for 0.18% of 5.50 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]    100.0    0.00    5.50                 main [1]
                5.03    0.00   17381/17381       DrawTiles [2]
                0.00    0.44   17381/17381       UpdateEntity [4]
                0.03    0.00   17381/17381       DrawEntity [6]
                0.00    0.00   17382/17382       GetCameraBounds [8]
                0.00    0.00       2/2           CreateTileType [10]
                0.00    0.00       1/1           GenerateWorld [11]
-----------------------------------------------
                5.03    0.00   17381/17381       main [1]
[2]     91.5    5.03    0.00   17381         DrawTiles [2]
-----------------------------------------------
                0.22    0.22   34762/34762       UpdateEntity [4]
[3]      8.0    0.22    0.22   34762         CollisionWithTile [3]
                0.22    0.00 64692134/64709515     GetCollider [5]
-----------------------------------------------
                0.00    0.44   17381/17381       main [1]
[4]      8.0    0.00    0.44   17381         UpdateEntity [4]
                0.22    0.22   34762/34762       CollisionWithTile [3]
-----------------------------------------------
                0.00    0.00   17381/64709515     DrawEntity [6]
                0.22    0.00 64692134/64709515     CollisionWithTile [3]
[5]      4.0    0.22    0.00 64709515         GetCollider [5]
-----------------------------------------------
                0.03    0.00   17381/17381       main [1]
[6]      0.5    0.03    0.00   17381         DrawEntity [6]
                0.00    0.00   17381/64709515     GetCollider [5]
-----------------------------------------------
                0.00    0.00  488278/488278      GenerateWorld [11]
[7]      0.0    0.00    0.00  488278         SetTile [7]
-----------------------------------------------
                0.00    0.00   17382/17382       main [1]
[8]      0.0    0.00    0.00   17382         GetCameraBounds [8]
-----------------------------------------------
                0.00    0.00     512/512         GenerateWorld [11]
[9]      0.0    0.00    0.00     512         fnlGetNoise2D [9]
                0.00    0.00     512/512         _fnlTransformNoiseCoordinate2D [26]
                0.00    0.00     512/512         _fnlGenNoiseSingle2D [24]
-----------------------------------------------
                0.00    0.00       2/2           main [1]
[10]     0.0    0.00    0.00       2         CreateTileType [10]
-----------------------------------------------
                0.00    0.00       1/1           main [1]
[11]     0.0    0.00    0.00       1         GenerateWorld [11]
                0.00    0.00  488278/488278      SetTile [7]
                0.00    0.00     512/512         fnlGetNoise2D [9]
                0.00    0.00       1/1           fnlCreateState [13]
                0.00    0.00       1/1           RefreshEdgeBuffer [12]
-----------------------------------------------
                0.00    0.00       1/1           GenerateWorld [11]
[12]     0.0    0.00    0.00       1         RefreshEdgeBuffer [12]
-----------------------------------------------
                0.00    0.00       1/1           GenerateWorld [11]
[13]     0.0    0.00    0.00       1         fnlCreateState [13]
-----------------------------------------------
                0.00    0.00    1252/1252        _fnlSingleSimplex2D [25]
[21]     0.0    0.00    0.00    1252         _fnlGradCoord2D [21]
                0.00    0.00    1252/1252        _fnlHash2D [22]
-----------------------------------------------
                0.00    0.00    1252/1252        _fnlGradCoord2D [21]
[22]     0.0    0.00    0.00    1252         _fnlHash2D [22]
-----------------------------------------------
                0.00    0.00    1024/1024        _fnlSingleSimplex2D [25]
[23]     0.0    0.00    0.00    1024         _fnlFastFloor [23]
-----------------------------------------------
                0.00    0.00     512/512         fnlGetNoise2D [9]
[24]     0.0    0.00    0.00     512         _fnlGenNoiseSingle2D [24]
                0.00    0.00     512/512         _fnlSingleSimplex2D [25]
-----------------------------------------------
                0.00    0.00     512/512         _fnlGenNoiseSingle2D [24]
[25]     0.0    0.00    0.00     512         _fnlSingleSimplex2D [25]
                0.00    0.00    1252/1252        _fnlGradCoord2D [21]
                0.00    0.00    1024/1024        _fnlFastFloor [23]
-----------------------------------------------
                0.00    0.00     512/512         fnlGetNoise2D [9]
[26]     0.0    0.00    0.00     512         _fnlTransformNoiseCoordinate2D [26]
-----------------------------------------------

 This table describes the call tree of the program, and was sorted by
 the total amount of time spent in each function and its children.

 Each entry in this table consists of several lines.  The line with the
 index number at the left hand margin lists the current function.
 The lines above it list the functions that called this function,
 and the lines below it list the functions this one called.
 This line lists:
     index	A unique number given to each element of the table.
		Index numbers are sorted numerically.
		The index number is printed next to every function name so
		it is easier to look up where the function is in the table.

     % time	This is the percentage of the `total' time that was spent
		in this function and its children.  Note that due to
		different viewpoints, functions excluded by options, etc,
		these numbers will NOT add up to 100%.

     self	This is the total amount of time spent in this function.

     children	This is the total amount of time propagated into this
		function by its children.

     called	This is the number of times the function was called.
		If the function called itself recursively, the number
		only includes non-recursive calls, and is followed by
		a `+' and the number of recursive calls.

     name	The name of the current function.  The index number is
		printed after it.  If the function is a member of a
		cycle, the cycle number is printed between the
		function's name and the index number.


 For the function's parents, the fields have the following meanings:

     self	This is the amount of time that was propagated directly
		from the function into this parent.

     children	This is the amount of time that was propagated from
		the function's children into this parent.

     called	This is the number of times this parent called the
		function `/' the total number of times the function
		was called.  Recursive calls to the function are not
		included in the number after the `/'.

     name	This is the name of the parent.  The parent's index
		number is printed after it.  If the parent is a
		member of a cycle, the cycle number is printed between
		the name and the index number.

 If the parents of the function cannot be determined, the word
 `<spontaneous>' is printed in the `name' field, and all the other
 fields are blank.

 For the function's children, the fields have the following meanings:

     self	This is the amount of time that was propagated directly
		from the child into the function.

     children	This is the amount of time that was propagated from the
		child's children to the function.

     called	This is the number of times the function called
		this child `/' the total number of times the child
		was called.  Recursive calls by the child are not
		listed in the number after the `/'.

     name	This is the name of the child.  The child's index
		number is printed after it.  If the child is a
		member of a cycle, the cycle number is printed
		between the name and the index number.

 If there are any cycles (circles) in the call graph, there is an
 entry for the cycle-as-a-whole.  This entry shows who called the
 cycle (as parents) and the members of the cycle (as children.)
 The `+' recursive calls entry shows the number of function calls that
 were internal to the cycle, and the calls entry for each member shows,
 for that member, how many times it was called from other members of
 the cycle.

Copyright (C) 2012-2023 Free Software Foundation, Inc.

Copying and distribution of this file, with or without modification,
are permitted in any medium without royalty provided the copyright
notice and this notice are preserved.

Index by function name

   [3] CollisionWithTile       [5] GetCollider            [21] _fnlGradCoord2D (tile.c)
  [10] CreateTileType         [12] RefreshEdgeBuffer      [22] _fnlHash2D (tile.c)
   [6] DrawEntity              [7] SetTile                [25] _fnlSingleSimplex2D (tile.c)
   [2] DrawTiles               [4] UpdateEntity           [26] _fnlTransformNoiseCoordinate2D (tile.c)
  [11] GenerateWorld          [23] _fnlFastFloor (tile.c) [13] fnlCreateState
   [8] GetCameraBounds        [24] _fnlGenNoiseSingle2D (tile.c) [9] fnlGetNoise2D
