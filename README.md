# Banker_algorithm
The banker’s algorithm is a resource allocation and deadlock avoidance algorithm that tests for safety . In This project I implemented the algorithm using c++ and the implementation mainly depends on two dimentional vectors. The inputs are: number of processes,number of resources,alloation matrix,max matrix,available matrix,user can enquiry safe state,user can enquiry immediate request . The outputs are: need matrix,answer if the system is in safe state (and print sequence) or not , answer if the resource can be allocated to the process (and print sequence) or not .

## Pseudo Code
### Safety Algorithm

    1) Let Work and Finish be vectors of length ‘m’ and ‘n’ respectively.
    Initialize: Work = Available
    Finish[i] = false; for i=1, 2, 3, 4….n

    2) Find an i such that both
    a) Finish[i] = false
    b) Needi <= Work
    if no such i exists goto step (4)

    3) Work = Work + Allocation[i]
    Finish[i] = true
    goto step (2)

    4) if Finish [i] = true for all i
    then the system is in a safe state
    
### Resource-Request Algorithm

    1) If Requesti <= Needi
    Goto step (2) ; otherwise, raise an error condition, since the process has exceeded its maximum claim.

    2) If Requesti <= Available
    Goto step (3); otherwise, Pi must wait, since the resources are not available.

    3) Have the system pretend to have allocated the requested resources to process Pi by modifying the state as
    follows:
    Available = Available – Requesti
    Allocationi = Allocationi + Requesti
    Needi = Needi– Requesti


### Steps:

First: the user is asked to enter the number of processes and number of resources. 

Second: user enter allocation matrix , max matrix and available matrix. 

Third: the need matrix is printed . 

Fourth The program ask if you want to check safe state of the system or ask  if immediate request by one of the processes can be granted. 

You can answer with safestate if you want safe state or answer with immediaterequest if you want immediate request. 

##### The user entered safestate: 

First: The program will print whether the system is in safe state or not and if it is in safe state it print the sequence of processes. 

Second: The program ask if you want to check safe state of the system or ask  if immediate request by one of the processes can be granted. 

##### The user Entered immediaterequest: 

First: the program will ask you to enter the process number 

Second: The program will ask you to enter the request 

Third: The program will print whether the system is in safe state or not and if it is in safe state it print the sequence of processes and that the resource can be allocated successfully to the required process . 

And if it’s not in safe state it will also print that the resource cannot be allocated to the required process. 

Fourth: The program ask if you want to check safe state of the system or ask  if immediate request by one of the processes can be granted. 

And so on , until you enter exit. 

### Example:



<div align="center">
<img src="https://github.com/nouraan-ahmed/Banker_algorithm/blob/main/img/ex.png" width="550" height="600" >  
</div>  
