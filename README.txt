=================================================
=			   	 INSTRUCTIONS     		        =
=================================================
- make (creates executable named "sort")
- ./sort (runs sorting algorithm, prints running time results to output.txt)
- python plotting.py (creates scatter plot png and opens a matplotlib window to view the scatterplot)


=================================================
=				   	 Times	     		        =
=================================================
Time it takes to run all 11 different input lengths per sort and with printing/debugging enabled

name_of_sort: minutes:seconds
-----------------------------

Insertion Sort: 13:21
Merge Sort: 00:03
Heap Sort: 00:03
Quick Sort: 00:03
Counting Sort: 00:04
Radix Sort: 00:04
Bucket Sort: 00:04


=================================================
=				   	 Notes	     		        =
=================================================
-Compiled with g++ -std=c++11

-Each sort is in its own directory. Within each directory is a makefile, cpp file, and python file, txt file, png file, and an executable

-I have already created the executable, txt file, and scatterplot png and included them in each directory. If you want to create a new executable with "make", it will overwrite the current executable. If you want to create a new txt file with "./sort", it will overwrite the current txt file. If you want to create a new png with "python plotting.py", it will overwrite the current one. 

- For the quicker sorting algorithms (coutning, radix, bucket), the time complexity graph may not be apparent. This is due to how much it is zoomed in. You will notice the correct time complexity if it is zoomed out. I have included a separate image in each of these 3 sort's directories named "scatterplot_fixed_zoom.png" that I have manually zoomed out to to accurately portray the time complexity graph
