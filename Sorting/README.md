### Sorting process
- Selection Sort
	- 
	```
	initial array:  29 10 14 [37] 13
	after 1st swap: [29] 10 14 13 37
	after 2nd swap: 13 10 [14] 29 37
	after 3rd swap: [13] 10 14 29 37
	after 4th swap: 10  13  14 29 37
	```

- Bubble Sort
	-
	```							Pass 1							Pass 2
	initial array: 		[29] [10] 14 37 13					[10] [14] 29 13 37
				   		10 [29] [14] 37 13					10 [14] [29] 13 37
				   		10 14 [29] [37] 13					10 14 [29] [13] 37
				   		10 14 29 [37] [13]					10 14  13   29  37
				   		10  14  29 13 [37]					
	```
- Insertion Sort
	-
	```
	Initially, the sorted region is array[0], which is 29, and the unsorted region is the rest of the array. Take the first item in the unsorted region (10) and insert it into its proper position in the sorted region. The insertion requires the array entries to be shifted to make room for the inserted item:
	...
	initial array:  [29] |10| 14  37 13 	copy 10
					    \
					 29  29   14  37 13		shift 29
					[10  29] |14| 37 13 	insert (paste) 10; copy 14
						   \
					 10 29  29    37 13		shift 29
					[10 14 29] |37|  13		insert 14; copy 37; insert 37 on top of itself
					[10  14 29  37] |13|	copy 13
						   \  \  \
					 10  14 14 29 37		shift 37, 29, 14
					[10  13  14  29  37]	insert 13
	```