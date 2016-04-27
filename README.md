# OrejolaFinalProject
Final Project for CSCI 2270

Edit: 4/26/16

Project Summary:

Program will be for companies to keep track of employees for n-branches. The user will name his or her company,
and will have the ability to keep track of branch's employees. The user will be requested to input the name of
the manager and add all subordinates to for each branch employee. The program models an n-ary tree where each
node has a vector of node pointers for each of the nodes subordinates. The user is requested to name and give a
title for each employee and who they are subordinate too. The program has the capcity to print the employees sorted
by hierarchy, as well out print the employees for each branch. 

How to Run:

To run the program download the "narytree.cpp", "narytree.h", and "finalproject.cpp" from this github reposetory,
then store the 3 files into a single folder of your liking. Open up the IDE of your choice (eclipse, codeblocks, geaney)
then following the standard procedure for the IDE of your choice build and compile the files.

Example construction of "Company Branches"

Name your company: Target
Add branch manager: Ricky (Now Ricky is the manager of branch 1)
Add branch manager: Bob   (Now Bob is the manager of branch 2)
Add employee: 
	Employee name: Liz
	Branch for Liz: 1 (Now Liz is part of branch 1)
	Does Liz work under Ricky? (Y/N): Y (Now Liz is part of the subordinates vector for Ricky)
Add employee: 
	Employee name: Guy
	Branch for Guy: 1 (Now Guy is part of branch 1)
	Does Liz work under Ricky? (Y/N): Y (Now Guy is part of the subordinates vector for Ricky)
Add employee: 
	Employee name: Jerri
	Branch for Jerri: 1 (Now Guy is part of branch 1)
	Does Liz work under Ricky? (Y/N): N (Now Program will ask who under Ricky (Guy, Liz) does Jerri work for)
	Who is superior to Jerri? -Guy, -Liz: Liz (Now Jerri is part of the subordinates vector for Liz)
Print Branch: 1 (Print the employees for branch 1)
Rank 1:Name: Ricky
Rank 2:---Name: Liz
Rank 3:------Name: Jerri
Rank 2:---Name: Guy


System Requirements:
No system requirements. Works for all operating systems. 

Group Members:
Oliver Orejola

Open issues/bugs:
There are a few open bugs within the program. The major issue at hand is the functionality of the "printallbranches" method.
When adding a new employee A the user is asked to if some employee B is superior to another employee or not, if the user inputs
a "N" for the (Y/N) choice when B has no subordinates the program breaks down.
