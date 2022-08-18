# How to Use the CovidTest

## Introduction of CovidTest

The project has been compiled by g++. 

The executable file is in  `.../2021013442/COVIDTest/CovidTest.exe` or you can compiled it by yourself, and Makefile is in `.../2021013442/COVIDTest/COVIDTest/Makefile`.

## Command Lines

CovidTest has two main parts: Server and Client. There would be an input prompt (`(server) >>` , `(client) >>`) to tell you which part is being operated.

You need to set input and output file path on the server and load all users' data to begin with command lines. And you can also use the command lines to register, log in, creat tube etc. on the client.

You can use the command lines in the TestCommand.txt to test this program.

### Server

`set_fp 1 .../2021013442/COVIDTest/Data/OriginUserData` 
`1` means setting the file of origin users' data
`2` means setting the file of users' test result
`3` means setting the file of tubes' test result and related people with each tube
The following part `.../2021013442/COVIDTest/Data/OriginUserData` means file path

`load`
using this command to load users's data from the designative file you have set before and enter the client

### Client

`register name id password` : register a new user

`login id password` : log in

`logout` : log out

`set_admin id` : set a person with id to be an administrator

`set_collector id` : set a person with id to be an collector

`set_entry id` : set a person with id to be an entry staff

`new_tube YYYY/MM/DD HH:MM:SS XXXXXX` : creat a new tube with the following serial number

`fill_tube id YYYY/MM/DD HH:MM:SS` : set tested person's ID and sampling time

`set_result YYYY/MM/DD HH:MM:SS XXXXXX YYYY/MM/DD HH:MM:SS TestResult` : set tube's test result and entry time, and `TestResult` should be `negative` or `positive`

`quit` : close the program and save the test result in the designative file which has been set on server

### Others

Author reckon that this program has a good robustness and it can deal with almost any illegal input, and then feed back error message to user
