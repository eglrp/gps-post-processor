all:
	g++ -c src/ClientGpsData.cpp -o build/ClientGpsData.o
	g++ -c src/CsvHandler.cpp -o build/CsvHandler.o
	g++ src/GpsPostProcessor.cpp src/ClientGpsData.cpp src/CsvHandler.cpp -o build/GpsPostProcessor
	g++ -c src/UnitConverter.cpp -o build/UnitConverter.o -Igpstk/src/
clean:
	rm build/*
