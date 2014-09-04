#Instituto Superior Técnico


##Analysis and Synthesis Algorithms 


###2013/2014 


###1st Draft 


####Delivery Deadline: March 21, 2014 




##The Problem 

Nowadays there are many ways to share information (texts, images, videos, etc.) between
people. Some people end up forming groups such that when any 
person in the group gets something, everyone in the group has access to this information through 
shares some sequence. 
Suppose that each person has a number of other people with whom you share what 
receives. Their task is to classify people into groups for sharing, so that when 
one group of people gets something, all the others will also receive. 


##Input 

The input file should contain information about the shares: 

A line number of entities N, and the number of shares P. 

A list of P lines, wherein every line contains two integers u and v (separated by a blank)
which represent a share. Each line indicates that the person u sharing what gets to see. 

It is assumed that the identification of the persons is an integer between 1 and N. 


##Output 

The program should write to output the following information: 

A line with the maximum number of groups of people who share information; 

A line with the maximum size of the largest group of people who share information; 

A line with the maximum number of groups of people who share information only 

within the group; 




###Examples 


####Input 1 

```
8 10 
1 2 
1 3 
3 4 
4 2 
2 1 
2 5 
5 6 
6 7 
7 5 
4 8
```

####Output 1 

```
3 
4 
2 
2
```


####Input 2 

```
7 5 
2 3 
3 4 
5 6 
6 7 
7 5
```

####Output 2 

```
5 
3 
3
```



##Implementation 

The implementation of the project should be done preferably using programming languages 
C or C ++. Submissions in Java are also acceptable, but must have 
more careful with some implementation aspects. 
The time required to implement this project is less than 10 hours. 



##Submission of Project 

The submission of the project should include a summary report and a file with the source code 
solution. Information on the possible programming languages ​​is available on the website 
Mooshak the system. The programming language is identified by the file extension. 
For example, a project written in C should be .c extension. After compilation, the program 
resulting should read the standard input and write to standard output. information 
about options and restrictions compilation can be obtained through the 'help' button on the system 
Mooshak. The compilation command should not produce output, otherwise it will be considered 
a compilation error. The report must be submitted in PDF format with no more than 
4 pages, 12pt font, and 3cm margin. The report should include a brief introduction, 
the description of the solution, the theoretical analysis and experimental evaluation of the results. The report 
shall include any references that have been used in the project. reports 
which are not delivered in PDF format will note 0. The source code should be submitted 
Mooshak through the system and the report (in PDF format) should be submitted via the 
Phoenix. The source code is automatically evaluated by Mooshak system. note that
only the last submission will be considered for evaluation. All Submissions 
earlier will be ignored; this includes the source code and the report. 
Students are encouraged to submit as soon as possible, preliminary solutions to 
Mooshak the system and the Phoenix. Note that it is also possible to submit several times in Phoenix 
and that reports will not be accepted after the deadline and no extension of time. 
The Mooshak system indicates the time available for the project is submitted. projects 
must be subjected to Mooshak system; there is no other form of submission 
project. The reports must be submitted in the Phoenix system; there is no other way to 
submission of reports. 



##Rating 

The project should be done in groups of one or two students and will be evaluated in two phases. 
In the first phase, during submission, each implementation will be performed on a set of 
tests, which represent 80% of the final grade. In the second stage, the report will be evaluated. The 
note of the report contributes 20% of the final grade. 



##Automatic evaluation 

The first phase is automatically evaluated with a test set, which are 
executed on a computer with GNU / Linux operating system. It is essential that the code 
source compile without error and respect the standard input and output indicated above. the 
projects that do not meet the specified formats will be penalized and may be graded 0, 
If all tests fail. A reduced set of tests used by Mooshak system 
will be public. Most tests will not be disclosed before submission. However, 
all tests will be available after the deadline for submission of the project. In addition to checking 
the correction of the output produced, the evaluation environment restricts the memory and time 
available execution. Most of the tests runs the diff as follows: 

diff output result 

The result file contains the output generated by the executable from the input file. The 
output file contains the expected value. A program passes a test and receives the value 
corresponding, when the diff command does not report any differences. There are 16 trials. 
Thus, the system reports a value between 0 and 16. 



##Detection of Copies

The evaluation of project includes a procedure for detection of copies. Submission of a 
project involves a commitment that the work was done exclusively by students.

Violation of this commitment or attempt to submit code that was not developed by 
group implies failure in the course, all students involved (INCLUDING 
students who provided the code). Any attempt to cheat, direct or indirect, 
be communicated to the Pedagogical Council of IST, the course coordinator, and will be penalized 
according to the rules approved by the University and published in the "Official Gazette". 
