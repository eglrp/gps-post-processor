LIBS=-lgpstk
LIB_PATH=-L/usr/local/lib/
I_PATH=-Igpstk/src/

all:
	g++ -c src/ClientGpsData.cpp -o build/ClientGpsData.o
	g++ -c src/CsvHandler.cpp -o build/CsvHandler.o
	g++ -c src/UnitConverter.cpp -o build/UnitConverter.o $(LIBS) $(LIB_PATH) $(I_PATH)
	g++ src/GpsPostProcessor.cpp src/ClientGpsData.cpp src/CsvHandler.cpp src/UnitConverter.cpp -o build/GpsPostProcessor $(LIBS) $(LIB_PATH) $(I_PATH)
clean:
	rm build/*
