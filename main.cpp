// all menu :
// 1. Add Food Item
// 2. Display Food Menu
// 3. Linear Search Food
// 4. Binary Search Food
// 5. Sort Food By Price
// 6. Add Order
// 7. Display Orders
// 8. Undo Last Order
// 9. Process Delivery
// 10. Add Restaurant
// 11. Display Restaurants
// 12. Assign Delivery Boy
// 0. Exit


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

// ======================================================
// MEMBER 1 : Arrays + Linked List
// ======================================================

struct Food
{
    int id;
    string name;
    int price;
};

vector<Food> menuItems;

// Add Food Item
void addFood()
{
    Food f;

    cout << "Enter Food ID: ";
    cin >> f.id;

    cout << "Enter Food Name: ";
    cin >> f.name;

    cout << "Enter Food Price: ";
    cin >> f.price;

    menuItems.push_back(f);

    cout << "Food Added Successfully!\n";
}

// Linked List for Orders

struct OrderNode
{
    int orderId;
    string foodName;
    OrderNode* next;

    OrderNode(int id, string food)
    {
        orderId = id;
        foodName = food;
        next = NULL;
    }
};

OrderNode* head = NULL;

// Add Order
void addOrder(int id, string food)
{
    OrderNode* newNode = new OrderNode(id, food);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    OrderNode* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Display Orders
void displayOrders()
{
    if(head == NULL)
    {
        cout << "No Orders Available\n";
        return;
    }

    OrderNode* temp = head;

    cout << "\n------ Orders ------\n";

    while(temp != NULL)
    {
        cout << "Order ID: "
             << temp->orderId
             << " | Food: "
             << temp->foodName
             << endl;

        temp = temp->next;
    }
}

// ======================================================
// MEMBER 2 : Stack + Queue
// ======================================================

stack<int> undoStack;
queue<int> deliveryQueue;

// Save order for undo
void saveOrder(int id)
{
    undoStack.push(id);
}

// Undo Last Order
void undoOrder()
{
    if(undoStack.empty())
    {
        cout << "No Order To Undo\n";
        return;
    }

    cout << "Order "
         << undoStack.top()
         << " Removed Successfully\n";

    undoStack.pop();
}

// Delivery Queue
void addToQueue(int id)
{
    deliveryQueue.push(id);
}

// Process Delivery
void processDelivery()
{
    if(deliveryQueue.empty())
    {
        cout << "No Pending Deliveries\n";
        return;
    }

    cout << "Delivering Order ID : "
         << deliveryQueue.front()
         << endl;

    deliveryQueue.pop();
}

// ======================================================
// MEMBER 3 : Searching + Sorting
// ======================================================

// Linear Search
void linearSearch(string item)
{
    bool found = false;

    for(Food food : menuItems)
    {
        if(food.name == item)
        {
            cout << "Food Found!\n";
            cout << "ID: " << food.id
                 << " Price: " << food.price
                 << endl;

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "Food Not Found\n";
    }
}

// Sort using Insertion Sort
void insertionSort()
{
    int n = menuItems.size();

    for(int i = 1; i < n; i++)
    {
        Food key = menuItems[i];

        int j = i - 1;

        while(j >= 0 &&
              menuItems[j].price > key.price)
        {
            menuItems[j + 1] = menuItems[j];
            j--;
        }

        menuItems[j + 1] = key;
    }

    cout << "Sorted Using Insertion Sort\n";
}

// Binary Search
void binarySearchFood()
{
    if(menuItems.empty())
    {
        cout << "No Food Items Available\n";
        return;
    }

    insertionSort();

    int target;

    cout << "Enter Food ID To Search: ";
    cin >> target;

    int low = 0;
    int high = menuItems.size() - 1;

    sort(menuItems.begin(),
         menuItems.end(),
         [](Food a, Food b)
         {
             return a.id < b.id;
         });

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(menuItems[mid].id == target)
        {
            cout << "Food Found\n";
            cout << menuItems[mid].name
                 << " Price = "
                 << menuItems[mid].price
                 << endl;

            return;
        }

        else if(menuItems[mid].id < target)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }

    cout << "Food Not Found\n";
}

// Display Food Menu
void displayFood()
{
    if(menuItems.empty())
    {
        cout << "Menu Empty\n";
        return;
    }

    cout << "\n------ FOOD MENU ------\n";

    for(Food food : menuItems)
    {
        cout << food.id
             << " | "
             << food.name
             << " | Rs."
             << food.price
             << endl;
    }
}

// ======================================================
// MEMBER 4 : BST + Greedy
// ======================================================

// BST Node

struct TreeNode
{
    string restaurant;

    TreeNode* left;
    TreeNode* right;

    TreeNode(string name)
    {
        restaurant = name;
        left = NULL;
        right = NULL;
    }
};

TreeNode* root = NULL;

// Insert Restaurant
TreeNode* insertRestaurant(TreeNode* root,
                           string name)
{
    if(root == NULL)
    {
        return new TreeNode(name);
    }

    if(name < root->restaurant)
    {
        root->left =
        insertRestaurant(root->left, name);
    }
    else
    {
        root->right =
        insertRestaurant(root->right, name);
    }

    return root;
}

// Display Restaurants
void inorder(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left);

    cout << root->restaurant << endl;

    inorder(root->right);
}

// Greedy Assignment
void assignDeliveryBoy()
{
    string boys[3] =
    {
        "Rahul",
        "Amit",
        "Suresh"
    };

    cout << "Assigned Delivery Boy : "
         << boys[0]
         << endl;
}

// ======================================================
// MAIN FUNCTION
// ======================================================

int main()
{
    int choice;

    while(true)
    {
        cout << "\n";
        cout << "=================================\n";
        cout << " FOOD DELIVERY SYSTEM\n";
        cout << "=================================\n";

        cout << "1. Add Food Item\n";
        cout << "2. Display Food Menu\n";
        cout << "3. Linear Search Food\n";
        cout << "4. Binary Search Food\n";
        cout << "5. Sort Food By Price\n";
        cout << "6. Add Order\n";
        cout << "7. Display Orders\n";
        cout << "8. Undo Last Order\n";
        cout << "9. Process Delivery\n";
        cout << "10. Add Restaurant\n";
        cout << "11. Display Restaurants\n";
        cout << "12. Assign Delivery Boy\n";
        cout << "0. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addFood();
                break;

            case 2:
                displayFood();
                break;

            case 3:
            {
                string name;

                cout << "Enter Food Name: ";
                cin >> name;

                linearSearch(name);

                break;
            }

            case 4:
                binarySearchFood();
                break;

            case 5:
                insertionSort();
                break;

            case 6:
            {
                int id;
                string food;

                cout << "Order ID: ";
                cin >> id;

                cout << "Food Name: ";
                cin >> food;

                addOrder(id, food);

                saveOrder(id);

                addToQueue(id);

                cout << "Order Added\n";

                break;
            }

            case 7:
                displayOrders();
                break;

            case 8:
                undoOrder();
                break;

            case 9:
                processDelivery();
                break;

            case 10:
            {
                string restaurant;

                cout << "Restaurant Name: ";
                cin >> restaurant;

                root =
                insertRestaurant(root,
                                 restaurant);

                cout << "Restaurant Added\n";

                break;
            }

            case 11:
                cout << "\nRestaurants:\n";
                inorder(root);
                break;

            case 12:
                assignDeliveryBoy();
                break;

            case 0:
                cout << "Program Ended\n";
                return 0;

            default:
                cout << "Invalid Choice\n";
        }
    }

    return 0;
}