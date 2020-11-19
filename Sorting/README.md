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
