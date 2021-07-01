import csv

inputFile = "keyMap.csv"
outputFile = "keyMap.txt"

outputArray = ['0x00'] * 256
cols = 8

with open(inputFile, 'r', newline='') as csvFile :
    rows = list(csv.reader(csvFile))

    for row in rows :
        inputString = '0x' + row[1]
        index = int(inputString, 0)
        outputString = '0x' + row[2]
        outputArray[index] = outputString

with open(outputFile, 'w') as txtFile :
    outputString = ''

    for i in range(256) :
        outputString += outputArray[i]
        outputString += ', '

        if i % cols == cols - 1 :
            txtFile.write(outputString + '\n')
            outputString = ''
