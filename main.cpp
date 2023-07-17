#include <iostream> //For input and output functionalities
#include <vector>   //To use vectors
#include <fstream>  //To work with files
#include <algorithm>//To use the sort function
#include <string>   //To get the functions related to stings
#include <chrono>   //To calculate time durations
#include <iomanip>  //To use the functions for formatting input/output operations

using namespace std;

chrono::system_clock::time_point timeStarted;
chrono::system_clock::time_point timeEnded;

//creating struct named order to hold the details of one order
typedef struct Order{
    string client_order_id;
    string instruments;
    int side;
    int quantity;
    double price;
    string trader_id;
    string order_id;
    string status;
    string reason;
}Order;

string transactionTime(){
    std::chrono::duration<double> duration = timeEnded - timeStarted;
    //SYSTEMTIME sTime = duration;
    // GetLocalTime(&sTime);
    //time_t started_Time = std::chrono::system_clock::to_time_t(timeStarted);
    //time_t ended_Time = std::chrono::system_clock::to_time_t(timeEnded);
    //time_t duration=ended_Time-started_Time;
    //tm* timeInfo = std::localtime(&duration);
    return to_string(duration.count());
    //stringstream buf;
//    buf << put_time(timeInfo, "%Y.%m.%d-%H.%M.%S") << "." << setfill('0') << setw(3) << duration%1000 << "\n";
//    buf << sTime.wYear << "-" << sTime.wMonth << "-" << sTime.wDay << " " << sTime.wHour << ":" << sTime.wMinute << ":" << sTime.wSecond << ":" << sTime.wMilliseconds;
    // return buf.str();

}

//creating three vectors to store data
vector<Order> orders;
vector<Order> buyOrders;
vector<Order> sellOrders;

int i=0;

void createOrderBooksAndReports(){
    cout<<"OrderBooks and Execution Books generated.\n";
    fstream fout;   //create an object of type fstream
    remove("OrderBookRose.csv");    //Remove previously existing data in the file
    fout.open("OrderBookRose.csv", ios::out | ios::app);    //open the file in append mode : out - write , app - append
    if(fout.is_open()){
        fout << "Order id" << "," << "Quantity" << "," << "Price" << "," << "Price" << "," << "Quantity" << "," <<  "Order id" << endl;
        fout.close();
    }
    remove("OrderBookLavender.csv");
    fout.open("OrderBookLavender.csv", ios::out | ios::app);
    if(fout.is_open()){
        fout << "Order id" << "," << "Quantity" << "," << "Price" << "," << "Price" << "," << "Quantity" << "," <<  "Order id" << endl;
        fout.close();
    }
    remove("OrderBookLotus.csv");
    fout.open("OrderBookLotus.csv", ios::out | ios::app);
    if(fout.is_open()){
        fout << "Order id" << "," << "Quantity" << "," << "Price" << "," << "Price" << "," << "Quantity" << "," <<  "Order id" << endl;
        fout.close();
    }
    remove("OrderBookTulip.csv");
    fout.open("OrderBookTulip.csv", ios::out | ios::app);
    if(fout.is_open()){
        fout << "Order id" << "," << "Quantity" << "," << "Price" << "," << "Price" << "," << "Quantity" << "," <<  "Order id" << endl;
        fout.close();
    }
    remove("OrderBookOrchid.csv");
    fout.open("OrderBookOrchid.csv", ios::out | ios::app);
    if(fout.is_open()){
        fout << "Order id" << "," << "Quantity" << "," << "Price" << "," << "Price" << "," << "Quantity" << "," <<  "Order id" << endl;
        fout.close();
    }
    remove("Execution_rep.csv");
    fout.open("Execution_rep.csv", ios::out | ios::app);
    if(fout.is_open()){
        fout << "Order ID"<< "," << "Client_order_id "<< "," << "Instruments" << "," << "Side" << "," << "Status" << "," << "Quantity" << "," << "Price" << "," << "Reason" << "," << "Trader_id" << "," << "Transaction_time" << endl;
        fout.close();
    }
}

void updateOrderBooks(Order od){
    fstream fout;
    if(od.instruments == "Rose"){
        fout.open("OrderBookRose.csv", ios::out | ios::app);
        if(fout.is_open()){
            if(od.side==1){
                fout << od.order_id << "," << od.quantity << "," << od.price <<  endl;
            }else{
                fout << "" << "," << "" << "," << ""<< "," << od.price << "," << od.quantity << "," << od.order_id << endl;
            }
            fout.close();

        }
    }else if(od.instruments == "Lavender"){
        fout.open("OrderBookLavender.csv", ios::out | ios::app);
        if(fout.is_open()){
            if(od.side==1){
                fout << od.order_id << "," << od.quantity << "," << od.price <<  endl;
            }else{
                fout << "" << "," << "" << "," << ""<< "," << od.price << "," << od.quantity << "," << od.order_id << endl;
            }
            fout.close();

        }
    }else if(od.instruments == "Lotus"){
        fout.open("OrderBookLotus.csv", ios::out | ios::app);
        if(fout.is_open()){
            if(od.side==1){
                fout << od.order_id << "," << od.quantity << "," << od.price <<  endl;
            }else{
                fout << "" << "," << "" << "," << ""<< "," << od.price << "," << od.quantity << "," << od.order_id << endl;
            }
            fout.close();

        }
    }else if(od.instruments == "Tulip"){
        fout.open("OrderBookTulip.csv", ios::out | ios::app);
        if(fout.is_open()){
            if(od.side==1){
                fout << od.order_id << "," << od.quantity << "," << od.price <<  endl;
            }else{
                fout << "" << "," << "" << "," << ""<< "," << od.price << "," << od.quantity << "," << od.order_id << endl;
            }
            fout.close();

        }
    }else if(od.instruments == "Orchid"){
        fout.open("OrderBookOrchid.csv", ios::out | ios::app);
        if(fout.is_open()){
            if(od.side==1){
                fout << od.order_id << "," << od.quantity << "," << od.price <<  endl;
            }else{
                fout << "" << "," << "" << "," << ""<< "," << od.price << "," << od.quantity << "," << od.order_id << endl;
            }
            fout.close();

        }
    }
}
void updateExecutionReport(Order od, int quantity = -1, double price = -1.0) {
    fstream fout;
    fout.open("Execution_rep.csv", ios::out | ios::app);
    if(fout.is_open()){
        timeEnded = chrono::system_clock::now();
        string transaction_time =transactionTime();
        fout << od.order_id << "," << od.client_order_id << "," << od.instruments << "," << od.side << "," << od.status << "," << od.quantity << "," << od.price << "," << od.reason << "," << od.trader_id << "," << transaction_time;
        fout << endl;
        fout.close();
    }
}
bool compareBuy(const Order & a, const Order & b) {
    return a.price > b.price;
}
bool compareSell(const Order & a, const Order & b) {
    return a.price < b.price;
}

void findOrder(Order &order, vector<Order> &buy, vector<Order> &sell){

    if (order.side == 1){//if buyer
        if (sell.empty()){//if sell vector is empty
            buy.push_back(order);//buy order is added to the vector buy
            sort(buy.begin(), buy.end(), compareBuy);
            if (order.status != "pFill")
                updateExecutionReport(order);
            return;
        }
        for (int j = 0; j < sell.size(); j++){
            Order s = sell[j];
            if (s.instruments != order.instruments)
                continue;
            if (s.price > order.price){
                buy.push_back(order);
                sort(buy.begin(), buy.end(), compareBuy);
                if (order.status != "pFill")
                    updateExecutionReport(order);
                return;
            }
            else if (s.price == order.price){
                if (s.quantity == order.quantity){
                    order.status = "Fill";
                    updateExecutionReport(order);
                    s.status = "Fill";
                    updateExecutionReport(s);
                    sell.erase(sell.begin() + j);
                    sort(sell.begin(), sell.end(), compareSell);

                    return;
                }else if (s.quantity < order.quantity){
                    order.status = "pFill";
                    order.quantity = order.quantity - s.quantity;
                    updateExecutionReport(order,s.quantity);
                    s.status = "Fill";
                    updateExecutionReport(s);
                    sell.erase(sell.begin() + j);
                    sort(sell.begin(), sell.end(), compareSell);

                    if (!sell.empty() || order.quantity != 0)
                        findOrder(order, buy, sell);

                    if (order.quantity > 0){
                        buy.push_back(order);
                        sort(buy.begin(), buy.end(), compareBuy);
                    }
                    return;
                }else{// sells.Quantity > quantity
                    order.status = "Fill";
                    updateExecutionReport(order);
                    s.quantity = s.quantity - order.quantity;
                    s.status = "pFill";
                    updateExecutionReport(s,order.quantity);
                    return;
                }
            }
            else{// sells.Price < price
                if (s.quantity == order.quantity){
                    order.status = "Fill";
                    updateExecutionReport(order, s.price);  //------------------------------------
                    s.status = "Fill";
                    updateExecutionReport(s);
                    sell.erase(sell.begin() + j);
                    sort(sell.begin(), sell.end(), compareSell);
                    return;
                }else if (s.quantity > order.quantity){
                    order.status = "Fill";
                    updateExecutionReport(order,s.price);
                    s.status = "pFill";
                    s.quantity = s.quantity - order.quantity;
                    updateExecutionReport(s,order.quantity);
                    return;
                }
                else // sells.Quantity < order.Quantity
                {
                    order.status = "pFill";
                    order.quantity = order.quantity - s.quantity;
                    updateExecutionReport(order,s.quantity, s.price);
                    s.status = "Fill";
                    updateExecutionReport(order);
                    sell.erase(sell.begin() + j);
                    sort(sell.begin(), sell.end(), compareSell);

                    if (!sell.empty() || order.quantity != 0)
                        findOrder(order, buy, sell);

                    if (order.quantity > 0){
                        buy.push_back(order);
                        sort(buy.begin(), buy.end(), compareBuy);
                    }
                    return;
                }
            }
        }
        buy.push_back(order);
        sort(buy.begin(), buy.end(), compareBuy);
        if (order.status != "pFill")
            updateExecutionReport(order);
    }
    else // sell
    {
        if (buy.empty()){//if buyOrders vector is empty
            sell.push_back(order);
            sort(sell.begin(), sell.end(), compareSell);
            if (order.status != "pFill")
                updateExecutionReport(order);
            return;
        }
        for (int j = 0; j < buy.size(); j++){
            Order b = buy[j];
            if (b.instruments != order.instruments)
                continue;
            if (b.price > order.price){//if b.price>order.price
                if (b.quantity == order.quantity){//if b.quantity==order.quantity
                    order.status = "Fill";
                    updateExecutionReport(order,b.price);
                    b.status = "Fill";
                    updateExecutionReport(b);
                    buy.erase(buy.begin() + j);
                    sort(buy.begin(), buy.end(), compareBuy);
                    return;
                }else if (b.quantity < order.quantity){//if b.quantity < order.quantity
                    order.status = "pFill";
                    order.quantity = order.quantity - b.quantity;
                    updateExecutionReport(order,b.quantity, b.price);
                    b.status = "Fill";
                    updateExecutionReport(b);
                    buy.erase(buy.begin() + j);
                    sort(buy.begin(), buy.end(), compareBuy);
                    if (!buy.empty() || order.quantity != 0)
                        findOrder(order, buy, sell);
                    if (order.quantity > 0){
                        sell.push_back(order);
                        sort(sell.begin(), sell.end(), compareSell);
                    }
                    return;
                }else{ // buys.Quantity > order.Quantity
                    order.status = "Fill";
                    updateExecutionReport(order,b.price);
                    b.status = "pFill";
                    b.quantity = b.quantity - order.quantity;
                    updateExecutionReport(b,order.quantity);
                }
            }
            else if (b.price == order.price){ //if b.price==order.price
                if (b.quantity > order.quantity){//if b.quantity>order.quantity
                    order.status = "Fill";
                    updateExecutionReport(order,b.price);
                    b.status = "pFill";
                    b.quantity = b.quantity - order.quantity;
                    updateExecutionReport(b,order.quantity);
                }
                else if (b.quantity == order.quantity){//if b.quantity==order.quantity
                    order.status = "Fill";
                    updateExecutionReport(order);
                    b.status = "Fill";
                    updateExecutionReport(b);
                    buy.erase(buy.begin() + j);
                    sort(buy.begin(), buy.end(), compareBuy);
                }
                else // buys.Quantity < order.Quantity
                {
                    order.status = "pFill";
                    order.quantity = order.quantity - b.quantity;
                    updateExecutionReport(order,b.quantity, b.price);
                    b.status = "Fill";
                    updateExecutionReport(b);
                    buy.erase(buy.begin() + j);
                    sort(buy.begin(), buy.end(), compareBuy);
                    if (!buy.empty() || order.quantity != 0)
                        findOrder(order, buy, sell);
                    if (order.quantity > 0){
                        sell.push_back(order);
                        sort(sell.begin(), sell.end(), compareSell);
                    }
                    return;
                }
            }
            else // buys.Price < order.Price
            {
                sell.push_back(order);
                sort(sell.begin(), sell.end(), compareSell);
                if (order.status != "pFill")
                    updateExecutionReport(order);
                return;
            }
        }
        sell.push_back(order);
        sort(sell.begin(), sell.end(), compareSell);
        if (order.status != "pFill")
            updateExecutionReport(order);
        }
}

void load_csv(){
    fstream fin;
    createOrderBooksAndReports();
    fin.open("Orders.csv", ios::in);
    if(!fin.is_open()){
        cout << "Error: Unable to open the Orders.csv file." << endl;
        return;
    }else{
        //fin << "Client Order ID" << "," << "Instrument" << "," << "Side" << "," << "Price" << "," << "Quantity" << "," << "Trader ID" << "," <<endl;
        string line;
        getline(fin, line); //skip the header line

        while(getline(fin, line)){
            timeStarted = chrono::system_clock::now();
            stringstream ss(line);

            string client_order_id, instrument, side, price, quantity, trader_id;
            string order_id,reason,transaction_time;
            string status="New";

            getline(ss, client_order_id, ',');
            getline(ss, instrument, ',');
            getline(ss, side, ',');
            getline(ss, quantity, ',');
            getline(ss, price, ',');
            getline(ss, trader_id, ',');
            order_id="ord"+ to_string(i);
            i++;

            int sideInt;
            double priceDouble;
            int quantityInt;

            try {
                sideInt = std::stoi(side);
                priceDouble = std::stod(price);
                quantityInt = std::stoi(quantity);
            } catch (const std::invalid_argument& e) {
                // Handle the exception when the conversion fails
                std::cout << "Error: Invalid argument encountered. Skipping the current line." << std::endl;
                continue;  // Skip to the next line or perform other appropriate actions
            }

            Order order = {client_order_id, instrument, sideInt, quantityInt,priceDouble, trader_id ,order_id, status ,reason};
            if(order.client_order_id.size()<=7){
                if((order.instruments=="Rose")||(order.instruments=="Lavender")||(order.instruments=="Lotus")||(order.instruments=="Tulip")||(order.instruments=="Orchid")){
                    if((order.side == 1 )||(order.side==2)){
                        if(order.price>0.0){
                            if(((order.quantity<1000)&&(order.quantity>10))&&(order.quantity%10==0)){
                                if(trader_id.size()<=7){
                                    //not rejected
                                    updateOrderBooks(order);
                                    orders.push_back(order);
                                    findOrder(order, buyOrders, sellOrders);
                                }else{
                                    order.status="rejected";
                                    order.reason="invalid trader_id";
                                }
                            }else{
                                order.status="rejected";
                                order.reason="invalid quantity";
                            }
                        }else{
                            order.status="rejected";
                            order.reason="invalid price";
                        }
                    }else{
                        order.status="rejected";
                        order.reason="invalid side";
                    }
                }else{
                    order.status="rejected";
                    order.reason="invalid instruments";
                }

            }else{
                order.status="rejected";
                order.reason="invalid client order id";
            }

            orders.push_back(order);
            findOrder(order, buyOrders, sellOrders);
        }
        fin.close();
    }
}
void addOrder(){
    cout<<"You chosed adding new Order\n";
    string client_order_id;
    string instrument;
    int side;
    double price;
    int quantity;
    string trader_id;
    string order_id,reason;
    string status="New";
    order_id="ord"+ to_string(i);
    i++;
    cout<<"\n";
    cout<<"Enter client_order_id (client Order Id should be less than or equal to 7 characters) : ";
    cin>>client_order_id;
    if(client_order_id.size()<=7){
        cout<<"Enter instrument (Instruments can be 'Rose, Lavender, Lotus, Tulip, Orchid) : ";
        cin>>instrument;
        if((instrument=="Rose")||(instrument=="Lavender")||(instrument=="Lotus")||(instrument=="Tulip")||(instrument=="Orchid")){
            cout<<"Enter Side (For buyers 1, for Sellers 2 ): ";
            cin>>side;
            if((side==1)||(side==2)){
                cout<<"Enter price (Enter Valid Price) : ";
                cin>>price;
                if(price>0.0){
                    cout<<"Enter quantity (Quantity should be 10<quantity<=1000 and a multiple of 10 ): ";
                    cin>>quantity;
                    if(((quantity<=1000)&&(quantity>10))&&(quantity%10==0)){
                        cout<<"Enter Trader ID : ";
                        cin>>trader_id;
                        if(trader_id.size()<=7){
                            cout<<"You have added valid data so your orderbooks and execution report will be generated soon\n";
                            Order order = {client_order_id, instrument, side, quantity, price, trader_id ,order_id, status ,reason};
                            updateOrderBooks(order);
                            fstream fout;
                            fout.open("Orders.csv", ios::out | ios::app);
                            fout << client_order_id << "," << instrument << "," << side << "," << quantity << "," << price << "," << trader_id << endl;
                            fout.close();
                            orders.push_back(order);
                            timeStarted = chrono::system_clock::now();
                            findOrder(order, buyOrders, sellOrders);
                        }else{
                            cout<<"Invalid trader ID. Enter Details again\n\n";
                        }
                    }else{
                        cout<<"Invalid quantity. Enter Details again\n\n";
                    }
                }else{
                    cout<<"Invalid Price. Enter Details again\n\n";
                }
            }else{
                cout<<"Invalid side. Enter Details again\n\n";
            }
        }else{
            cout<<"Invalid instruments. Enter Details again\n\n";
        }
    }else{
        cout<<"Invalid client_order_id. Enter Details again\n\n";
    }
}


int main() {
    cout<<"Welcome to Flora Lanka........... \n\n";
    load_csv();// load .csv's data to the vector order
    cout <<"existing Orders.csv's data are loaded \n\n";
    int ch=0;
    do{
        cout<<"Add order - ( press +1)\tTerminate - (press -1)\n";
        cout<<"Enter What you want to proceed : ";
        cin>>ch;
        cout<<"\n";
        switch(ch){
            case 1:
                addOrder();
                break;
            default:
                break;
        }
    }while(ch!=-1);
    return 0;
}