g++=g++ -std=c++11
CovidTest: main.cpp Client/Client.cpp Controller/Controller.cpp Debug/Debug.cpp Message/StdMessage.cpp Message/Command.cpp Server/Server.cpp Server/WorkFlow/FileIO.cpp Server/WorkFlow/TestResult.cpp Server/WorkFlow/TestTube.cpp Server/WorkFlow/TubeLabel.cpp Server/WorkFlow/User.cpp Server/WorkFlow/DateTimeBase/Date.cpp Server/WorkFlow/DateTimeBase/Time.cpp
	g++ -o CovidTest main.cpp Client/Client.cpp Controller/Controller.cpp Debug/Debug.cpp Message/StdMessage.cpp Message/Command.cpp Server/Server.cpp Server/WorkFlow/FileIO.cpp Server/WorkFlow/TestResult.cpp Server/WorkFlow/TestTube.cpp Server/WorkFlow/TubeLabel.cpp Server/WorkFlow/User.cpp Server/WorkFlow/DateTimeBase/Date.cpp Server/WorkFlow/DateTimeBase/Time.cpp
main.o: main.cpp Controller/Controller.hpp
	g++ -c main.cpp
Client.o: Client.cpp Message/StdMessage.hpp Message/Command.hpp
	g++ -c Client.o
Controller.o: Controller/Controller.cpp Message/Command.hpp Server/Server.hpp Client/Client.hpp
	g++ -c Controller.o
Debug.o: Debug/Debug.cpp
	g++ -c Debug.o
Command.o: Message/Command.cpp
	g++ -c Command.o
StdMessage.o: Message/StdMessage.cpp WorkFlow/TestResult.hpp WorkFlow/TubeLabel.hpp Server/WorkFlow/TestTube.hpp Server/WorkFlow/User.hpp
	g++ -c StdMessage.o
Server.o: Server/Server.cpp Server/WorkFlow/User.hpp Server/WorkFlow/TestTube.hpp Server/WorkFlow/FileIO.hpp Message/StdMessage.hpp Message/Command.hpp
	g++ -c Server.o
User.o: Server/WorkFlow/User.cpp Message/StdMessage.hpp Debug/Debug.hpp
	g++ -c User.o
TestTube.o: Server/WorkFlow/TestTube.cpp Message/StdMessage.hpp Debug/Debug.hpp Server/WorkFlow/User.hpp Server/WorkFlow/TubeLabel.hpp
	g++ -c TestTube.o
FileIO.o: Server/WorkFlow/FileIO.cpp Message/StdMessage.hpp 
	g++ -c FileIO.o
TubeLabel.o: Server/WorkFlow/TubeLabel.cpp Debug/Debug.hpp Server/WorkFlow/DateTimeBase/Date.hpp Server/WorkFlow/DateTimeBase/Time.hpp
	g++ -c TubeLabel.o
TestResult.o: Server/WorkFlow/TestResult.cpp
	g++ -c TestResult.o
Date.o: Server/WorkFlow/DateTimeBase/Date.cpp
	g++ -c Date.o
Time.o: Server/WorkFlow/DateTimeBase/Time.cpp
	g++ -c Time.o
clear:
	rm *.o main
