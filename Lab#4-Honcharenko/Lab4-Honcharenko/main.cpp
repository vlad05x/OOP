#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Train {
protected:
    int trainNumber;
    string departPoint;
    string arrivalPoint;
    string timeDepart;
    string timeArrival;
public:
    Train(int number, string depart, string arrival, string timeDep, string timeArriv)
        : trainNumber(number), departPoint(depart), arrivalPoint(arrival), timeDepart(timeDep), timeArrival(timeArriv) {
        if (timeDepart >= timeArrival) {
            throw invalid_argument("Error: Arrival time must be later than departure time.");
        }
    }

    virtual void showTrainInfo() const = 0;
    virtual ~Train() = default;

    int getTrainNumber() const {
        return trainNumber;
    }
    string getDepartPoint() const {
        return departPoint;
    }
    string getArrivalPoint() const {
        return arrivalPoint;
    }
    string getTimeDepart() const {
        return timeDepart;
    }
    string getTimeArrival() const {
        return timeArrival;
    }

    void setTrainNumber(int number) {
        trainNumber = number;
    }

    void setDepartPoint(const string& depart) {
        departPoint = depart;
    }

    void setArrivalPoint(const string& arrival) {
        arrivalPoint = arrival;
    }

    void setTimeDepart(const string& timeDep) {
        timeDepart = timeDep;
    }

    void setTimeArrival(const string& timeArriv) {
        timeArrival = timeArriv;
    }
};

class PassengerTrain : public Train {
private:
    int seatingCapacity;
    int sleepingCapacity;
public:
    PassengerTrain(int number, string depart, string arrival, string timeDep, string timeArriv, int seating, int sleeping)
        : Train(number, depart, arrival, timeDep, timeArriv), seatingCapacity(seating), sleepingCapacity(sleeping) {
        if (seating < 0 || sleeping < 0) {
            throw std::invalid_argument("Error: Seating and sleeping capacities must be non-negative.");
        }
    }

    int getSeatingCapacity() const {
        return seatingCapacity;
    }

    void setSeatingCapacity(int seating) {
        seatingCapacity = seating;
    }

    int getSleepingCapacity() const {
        return sleepingCapacity;
    }

    void setSleepingCapacity(int sleeping) {
        sleepingCapacity = sleeping;
    }

    void showTrainInfo() const override {
        cout << "\nPassenger train - " << "Number: " << trainNumber
             << ", From: " << departPoint << " To: " << arrivalPoint
             << ", Departure: " << timeDepart << ", Arrival: " << timeArrival
             << ", Seats: " << seatingCapacity << ", Sleeping: " << sleepingCapacity;
    }
};

class FreightTrain : public Train {
private:
    double maxCargoWeight;
    int numberOfWagons;

public:
    FreightTrain(int number, string depart, string arrival, string timeDep, string timeArriv, double cargoWeight, int wagons)
        : Train(number, depart, arrival, timeDep, timeArriv), maxCargoWeight(cargoWeight), numberOfWagons(wagons) {
        if (cargoWeight < 0 || wagons < 1) {
            throw std::invalid_argument("Error: Max cargo weight must be non-negative and wagons count positive.");
        }
    }

    double getMaxCargoWeight() const {
        return maxCargoWeight;
    }

    void setMaxCargoWeight(double cargoWeight) {
        maxCargoWeight = cargoWeight;
    }

    int getNumberOfWagons() const {
        return numberOfWagons;
    }

    void setNumberOfWagons(int wagons) {
        numberOfWagons = wagons;
    }

    void showTrainInfo() const override {
        std::cout << "\nFreight Train - " << "Number: " << trainNumber
                  << ", From: " << departPoint << " To: " << arrivalPoint
                  << ", Departure: " << timeDepart << ", Arrival: " << timeArrival
                  << ", Max Cargo Weight: " << maxCargoWeight << " tons, Wagons: " << numberOfWagons;
    }
};

int main() {
    try {
        PassengerTrain pt(125, "Kyiv", "Lviv", "10:00", "15:30", 50, 50);
        pt.showTrainInfo();

        pt.setSeatingCapacity(120);
        pt.setSleepingCapacity(60);
        pt.showTrainInfo();

        FreightTrain ft(202, "Odessa", "Kharkiv", "08:00", "18:00", 500.0, 20);
        ft.showTrainInfo();

        ft.setMaxCargoWeight(600.0);
        ft.setNumberOfWagons(25);
        ft.showTrainInfo();

    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
