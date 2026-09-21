
output: src/main.o src/Resource.o src/Reservation.o src/ReservationManager.o src/LinkedList.o src/WaitingList.o src/CancellationHistory.o
	g++ src/main.o src/Resource.o src/Reservation.o src/ReservationManager.o src/LinkedList.o src/WaitingList.o src/CancellationHistory.o -o output

src/main.o: src/main.cpp
	g++ -c src/main.cpp -Iinclude -o src/main.o

src/Resource.o: src/Resource.cpp include/Resource.h
	g++ -c src/Resource.cpp -Iinclude -o src/Resource.o

src/Reservation.o: src/Reservation.cpp include/Reservation.h
	g++ -c src/Reservation.cpp -Iinclude -o src/Reservation.o

src/ReservationManager.o: src/ReservationManager.cpp include/ReservationManager.h include/Resource.h
	g++ -c src/ReservationManager.cpp -Iinclude -o src/ReservationManager.o

src/LinkedList.o: src/LinkedList.cpp include/LinkedList.h include/Reservation.h
	g++ -c src/LinkedList.cpp -Iinclude -o src/LinkedList.o

src/WaitingList.o: src/WaitingList.cpp include/WaitingList.h
	g++ -c src/WaitingList.cpp -Iinclude -o src/WaitingList.o

src/CancellationHistory.o: src/CancellationHistory.cpp include/CancellationHistory.h include/Reservation.h
	g++ -c src/CancellationHistory.cpp -Iinclude -o src/CancellationHistory.o

clean:
	rm -f src/*.o output
