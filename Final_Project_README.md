# Final Project README

## Github Organization ##


**Code:** 

Our code is located in the github repository. Our graph class, node class, and utils folder are all located under the src folder. Under the data folder we have our 2 cvs's of data from the oldenburg data set. One csv file contains thee edge-startnode-endnode-distances and the other csv file contains nodeid-xcoordinates-ycoordinates for each road. Our Makefile is also located on the github repository which we use to execute our code. Also included is both the README.md that contains our project proposal, the results.md that contains restuls, and the Final_Project_README.md which is this current file that describes information about our tests, files, code and running instructions. 

**Tests:**

Our tests are located in the tests.cc folder found in the src folder in our github repository

**Written Report:** 

Our written report is located in the results.md folder in our github repository

**Presentation Video**

Our presentation video is located in our presentation our presentation link is located in results.md and README.md. 

## Running Instructions ##

Input data CSVs go into the data folder.
To make a graph out of them you can go to main and call the Graph constructor with the file name passed to it. There you can also run our algorithms. We have sample code there that does that for each algorithm and prints the resutls.


In terminal run:
**git clone https://github.com/leeabd123/Swashbuckling-Swaggering-Passageways/**

To execute the code in main run:
**make**
**bin/exec** To run main (we have some functions that you can mess around with)

To run our tests run:
**make tests**
**./bin/tests** To run tests 

Note: We have had trouble with our bin folder. It should be there but if it isn't you may need to create a folder called bin from the main repo.
