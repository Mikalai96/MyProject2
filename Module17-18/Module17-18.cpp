#include "Order.h"

int main() {
    std::vector<Order> orders;

    // Заполнение вектора заказов
    orders.emplace_back(1, 3000.0, OrderStatus::New);
    orders.emplace_back(2, 6000.0, OrderStatus::Processing);
    orders.emplace_back(3, 2000.0, OrderStatus::New);
    orders.emplace_back(4, 8000.0, OrderStatus::Processing);

    // Задержка для демонстрации времени заказа
    std::this_thread::sleep_for(std::chrono::seconds(6));

    // Обновление статуса заказов с помощью std::transform
    auto now = std::chrono::system_clock::now();
    std::transform(orders.begin(), orders.end(), orders.begin(), [&now](Order& order) {
        if (order.get_status() == OrderStatus::New &&
            std::chrono::duration_cast<std::chrono::seconds>(now - order.get_order_date()).count() > 5) {
            order.set_status(OrderStatus::Processing);
        }
        return order;
        });

    // Поиск первого заказа с суммой > 5000 и статусом "processing"
    auto it = std::find_if(orders.begin(), orders.end(), [](const Order& order) {
        return order.get_amount() > 5000 && order.get_status() == OrderStatus::Processing;
        });

    if (it != orders.end()) {
        std::cout << "Found order with ID: " << it->get_id()
            << ", Amount: " << it->get_amount() << '\n';
    }
    else {
        std::cout << "No matching order found.\n";
    }

    // Перемещение заказов со статусом "processing" в другой вектор
    std::vector<Order> processing_orders;

    auto partition_it = std::partition(orders.begin(), orders.end(), [](const Order& order) {
        return order.get_status() != OrderStatus::Processing;
        });

    std::move(partition_it, orders.end(), std::back_inserter(processing_orders));

    // Удаление перемещенных заказов из исходного вектора
    orders.erase(partition_it, orders.end());

    // Проверка содержимого векторов
    std::cout << "\nOrders in processing_orders:\n";
    for (const auto& order : processing_orders) {
        std::cout << "ID: " << order.get_id()
            << ", Amount: " << order.get_amount()
            << ", Status: " << status_to_string(order.get_status()) << '\n';
    }

    std::cout << "\nRemaining orders in original vector:\n";
    for (const auto& order : orders) {
        std::cout << "ID: " << order.get_id()
            << ", Amount: " << order.get_amount()
            << ", Status: " << status_to_string(order.get_status()) << '\n';
    }

    return 0;
}