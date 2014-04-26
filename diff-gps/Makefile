all:
	g++ -c src/ClientGpsData.cpp -o build/ClientGpsData.o
	g++ -c src/CsvHandler.cpp -o build/CsvHandler.o
	g++ src/GpsPostProcessor.cpp src/ClientGpsData.cpp src/CsvHandler.cpp -o build/GpsPostProcessor
clean:
	rm build/*
