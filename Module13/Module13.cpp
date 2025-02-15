#include "ServiceStation.h"
#include "Cars.h"

int main()
{
    // Создаем сервисную станцию для легковых машин с лимитом 5 машин
    ServiceStation<Car> stationPassengerCar(5);    
    // Добавляем машины в СТО
    stationPassengerCar.AddCar(Car("Toyota"));
    stationPassengerCar.AddCar(Car("Honda"));
    stationPassengerCar.AddCar(Car("Ford"));
    stationPassengerCar.AddCar(Car("Opel"));
    stationPassengerCar.AddCar(Car("Lada"));
    // Пробуем добавить машину сверх лимита
    stationPassengerCar.AddCar(Car("Mazda")); // Выдаст ошибку
    // Чиним все машины и перемещаем их в гараж
    stationPassengerCar.RepairAll();
    // Выводим содержимое гаража
    stationPassengerCar.DisplayGarage();
  
    // Создаем сервисную станцию для грузовых машин с лимитом 5 машин
    ServiceStation<Car> stationCargoCar(5);
    stationCargoCar.AddCar(Car("VW T2"));
    stationCargoCar.AddCar(Car("VW T3"));
    stationCargoCar.AddCar(Car("VW T4"));
    stationCargoCar.AddCar(Car("VW T5"));
    stationCargoCar.AddCar(Car("VW T6"));
    // Пробуем добавить машину сверх лимита
    stationCargoCar.AddCar(Car("Ford Transit")); // Выдаст ошибку
    // Чиним все машины и перемещаем их в гараж
    stationCargoCar.RepairAll();
    // Выводим содержимое гаража
    stationCargoCar.DisplayGarage();
    return 0;
}

