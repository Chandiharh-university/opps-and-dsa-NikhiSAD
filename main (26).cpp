#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath> // For calculations

using namespace std;

// Function to calculate the average production
double calculateAverage(const vector<double>& data) {
    double sum = 0;
    for (double value : data) {
        sum += value;
    }
    return (data.empty()) ? 0 : sum / data.size();
}

// Function to calculate the standard deviation (optional for advanced forecasting)
double calculateStandardDeviation(const vector<double>& data, double mean) {
    double variance = 0;
    for (double value : data) {
        variance += pow(value - mean, 2);
    }
    return sqrt(variance / data.size());
}

// Main Solar Forecasting Class
class SolarForecast {
private:
    vector<double> historicalData; // Stores historical solar energy production (kWh)
    double averageProduction;      // Average production calculated from historical data

public:
    SolarForecast() : averageProduction(0.0) {}

    void addData(double production) {
        historicalData.push_back(production);
        averageProduction = calculateAverage(historicalData);
        cout << "Data added successfully!\n";
    }

    void displayHistoricalData() const {
        if (historicalData.empty()) {
            cout << "No historical data available.\n";
            return;
        }
        cout << "\nHistorical Solar Energy Production (kWh):\n";
        for (size_t i = 0; i < historicalData.size(); ++i) {
            cout << "Day " << i + 1 << ": " << historicalData[i] << " kWh\n";
        }
    }

    void forecastProduction(int days) const {
        if (historicalData.empty()) {
            cout << "Insufficient data for forecasting.\n";
            return;
        }
        cout << "\nForecasted Solar Energy Production (kWh):\n";
        for (int i = 1; i <= days; ++i) {
            cout << "Day " << i << ": " << fixed << setprecision(2)
                 << averageProduction << " kWh (approx.)\n";
        }
    }

    void displayStatistics() const {
        if (historicalData.empty()) {
            cout << "No data available to calculate statistics.\n";
            return;
        }
        double stdDev = calculateStandardDeviation(historicalData, averageProduction);
        cout << "\nSolar Energy Production Statistics:\n";
        cout << "Average Production: " << fixed << setprecision(2) << averageProduction << " kWh\n";
        cout << "Standard Deviation: " << fixed << setprecision(2) << stdDev << " kWh\n";
    }
};

int main() {
    SolarForecast forecast;
    int choice;

    do {
        cout << "\nSolar Energy Production Forecasting Tool Menu:\n";
        cout << "1. Add Historical Data\n";
        cout << "2. Display Historical Data\n";
        cout << "3. Forecast Production\n";
        cout << "4. Display Statistics\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double production;
                cout << "Enter solar energy production (kWh) for a day: ";
                cin >> production;
                forecast.addData(production);
                break;
            }
            case 2:
                forecast.displayHistoricalData();
                break;
            case 3: {
                int days;
                cout << "Enter the number of days to forecast: ";
                cin >> days;
                forecast.forecastProduction(days);
                break;
            }
            case 4:
                forecast.displayStatistics();
                break;
            case 5:
                cout << "Exiting the tool. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}