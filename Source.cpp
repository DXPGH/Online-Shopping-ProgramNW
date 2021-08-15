#include <iostream>
#include <string>


using namespace std;




class Order_Details {

private:

  
    int order_num;

    int OrderID;

    string OrderType;

    bool Ready;

    string Ordered_items;

    bool Delivered;

public:

    

    Order_Details() {

        OrderID = -1;

        OrderType = -1;

        Ordered_items = "";

        Ready = Delivered = false;

    }

    

    Order_Details(int id, string type, string order) {

        OrderID = id;

        OrderType = type ;

        Ordered_items = order;

        Delivered = Ready = false;

    }

    

    void MarkDelivered() {

        Delivered = true;

    }

    

    bool isDelivered() {

        return Delivered;

    }

    

    bool isReady() {

        return Ready;

    }

    

    void MarkReady() {

        Ready = true;

    }

    

    void OrderDetails() {

        

        cout << "Order ID: " << OrderID << endl;

        cout << "OrderType: " << OrderType << endl;

        cout << "Ordered Items: " << Ordered_items << endl;

        cout << "Order Ready?: " << Ready << " yes" << endl;

        cout << "Order Delivered?: " << Delivered << " yes" << endl;

    }

};

int main()

{


    Order_Details order(458451, "bulk", "Samsung 55inch TV");

    order.OrderDetails();

    order.MarkReady();

    order.OrderDetails();

    order.MarkDelivered();

    order.OrderDetails();

    return 0;

}