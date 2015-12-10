door:
	g++ door.cpp -L/usr/lib -I/usr/include -lboost_system -lboost_thread -lcppnetlib-uri -lcppnetlib-client-connections -pthread -o door
clean:
	rm door
