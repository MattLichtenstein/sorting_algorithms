import matplotlib.pyplot as plot


NUMOFRUNS = 1  #only change this when changing the number of iterations in cpp file
NUMOFINPUTS = 11 #number of INPUTS -- must match NUMOFINPUTS in cpp file
INPUTS = [10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000]
arraySizes = []
runnningTimes = []
colors = ['#e34848', '#911ff3', '#4a8d35', '#cb6636', '#02ed21', '#0dc1c9', '#f1ea07', '#374908', '#A0A0A0', '#000000', '#C3B112' ]

#number of nested lists
for i in range(0, NUMOFINPUTS):
	arraySizes.append([])
	runnningTimes.append([])

#initialize matrix
for i in range(0, NUMOFINPUTS):
	arraySizes[i] = [INPUTS[i]] * NUMOFRUNS

#temp var to read from file and stores times
temp = open("output.txt",'r').read().split('\n')
temp.pop()

#fills the time matrix with data from output file
for i in range(0,NUMOFINPUTS):
	runnningTimes[i].extend(temp[i].split())

		
#creates / plots graph		
for i in range(0 ,NUMOFINPUTS):
	plot.scatter(arraySizes[i], runnningTimes[i], color=colors[i])
	
plot.savefig('scatterplot.png')

#display scatterplot
plot.title("Merge Sort")
plot.xlabel("Array Size")
plot.ylabel("Time (microseconds)")
plot.show()



