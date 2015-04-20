#include <iostream>
#include <vector>
#include <string>

//void sourceItem(std::string&, std::string&, long long&, std::vector<std::string>&, std::vector<std::vector<std::string > >&);
//source item
/* 
   item name
   item description
   item quantity
   item owner
*/

//void dynamicItem();
//dynamic item
/*
  item name
  item description
  item quantity
  item price
  item owner
*/

//void itemState();
//item state
/*
  item name
  item description
  item dynamic quantity
  item owned quantity
  */

long long answers(long long&);

int main(int argc, char** argv)
{
  //the item of yours
  std::vector<std::string> itemName; //the name of an item owned by an alias
  std::vector<std::string> itemDescription; //the description of an item owned by an alias
  std::vector<long long> itemQuantity; //the amount of an item owned by an alias

  //the items order book
  std::vector<std::string> lineOwner; //the location of alias name that owns this sale item
  std::vector<std::string> itemNames; //the location of an item's name corresponding to an alias the name's location is the same as it's owner
  std::vector<std::string> itemDescriptions; //location of description ^^
  std::vector<long long> itemQuantities; //location of the amounts for sale for an itemName and it's lineOwner
  std::vector<long long> itemPrice; //the location of the price for the ^^ ammount

  //the item's status floating sale quantity - this is data for an alias regarding an item that they own and also have for sale
  //otherwise saleQuantity would be zero if an alias owned some item
  std::vector<long long> saleQuantity;
  //original amount of this item at creation - the originator will always hold the source amount that an item was issued
  std::vector<long long> sourceQuantity;

  //user alias
  //std::string userAlias = "dally";

  //starCoin storage
  long long starCoins = 250000;

  //user alias storage
  std::vector<std::string> aliasVector;

  long long currentAliasIndex = aliasVector.size() - 1;

  std::string firstAnswerString;

  long long answer(-1);
  long long insideAnswer1(-1);
  long long insideAnswer2(-1);
  long long insideAnswer3(-1);
  std::string stringInsideAnswer;
  std::string stringInsideAnswer2;
  bool allGood = false;
  bool goodBalance = true;

  /*test
  lineOwner.push_back("inal");
  itemNames.push_back("Model T");
  itemDescriptions.push_back("1 Terabyte SSDisk 16 Gigabit RAM Disk");
  itemQuantities.push_back(60);
  itemPrice.push_back(32800);
  lineOwner.push_back("Francis");
  itemNames.push_back("new game");
  itemDescriptions.push_back("What 9000");
  itemQuantities.push_back(100000);
  itemPrice.push_back(10);
  lineOwner.push_back("Jason");
  itemNames.push_back("new game2");
  itemDescriptions.push_back("Over 9000");
  itemQuantities.push_back(9000);
  itemPrice.push_back(9001;
  //test */

  /*test
  aliasVector.push_back("inal"); //alias other than current user - aliasVector[0]
  aliasVector.push_back("Francis"); //alias other than current user - aliasVector[1]
  aliasVector.push_back("Jason"); //alias other than current user - aliasVector[2]
  //test */

  //username or alias request - this is to be replacable for a private key to an alias
  //add multiple alias support and alias management	
  std::cout << " welcome, what is your name? " << std::endl;
  std::getline(std::cin, firstAnswerString);
  aliasVector.push_back(firstAnswerString);

  

  std::cout << " welcome home " << aliasVector.at(0);
  do
  {
    std::cout << " pick one " << std::endl;
    std::cout << " 1. view starCoin Balance " << std::endl;
    std::cout << " 2. create your item  " << std::endl;
    if(itemQuantity.size() > 0)
    {
      std::cout << " 3. view inventory " << std::endl;
      std::cout << " 4. sell items " << std::endl;
    }
    if(lineOwner.size() > 0)
    {
      std::cout << " 5. buy items " << std::endl;
      std::cout << " 6. view sell book " << std::endl;
    }
    if(saleQuantity.size() > 0)
    std::cout << std::endl;
    std::cout << " 0. exit " << std::endl;
    std::cout << std::endl;
    answers(answer);
    switch(answer)
    {
      //0 entry exits the program
      case 0:
        return 0;
        break;

        //print out the starCoin balance
      case 1:
        std::cout << " starCoin: " << starCoins << std::endl;
        break;
        
        //simple item creation process
      case 2:
        std::cout << std::endl;
        std::cout << " what's the name of your item ? " << std::endl;
        std::cout << " ------type 'pleaseexit' to return to main menu " << std::endl;
        std::cin.ignore();
        std::getline(std::cin, stringInsideAnswer);
        if(stringInsideAnswer == "pleaseexit")
        {
          break;
        }
        std::cout << " how much of :: " << stringInsideAnswer << " :: do have to create? " << std::endl;
        std::cout << " -----type '-1' to return to main menu " << std::endl;
        std::cin >> insideAnswer1;
        if(insideAnswer1 == -1)
        {
          break;
        }
        std::cout << " how would you describe :: " << stringInsideAnswer << " :: in less than 160 characters " << std::endl;
        std::cout << " -----type 'pleaseexit' to return to main menu " << std::endl;
        std::cin.ignore();
        std::getline(std::cin, stringInsideAnswer2);
        if(stringInsideAnswer2 == "pleaseexit")
        {
          break;
        }
        
        //store the newly created item's name
        itemName.push_back(stringInsideAnswer);

        //store the description of the item
        itemDescription.push_back(stringInsideAnswer2);

        //store the initial quantity the item is made with
        itemQuantity.push_back(insideAnswer1);

        //store the static source amount for all ownerships
        sourceQuantity.push_back(insideAnswer1);
        //this one should be constant at creation

        saleQuantity.push_back(0);

        break;

        //simply list all items owned by the current alias
        case 3:
          if(itemQuantity.size() < 1)
          {
            break;
          }
          std::cout << " this is a list of the items you have created or bought " << std::endl;
          for(long long i=0; i<(long)itemName.size(); ++i)
          {
            std::cout << " Index: " << i << " | Name: " << itemName[i] << " | Quantity: " << itemQuantity[i] << " | Description: " << itemDescription[i] << std::endl;
          }

          break;
        //sell items from list of owned items
        case 4:
          if(itemQuantity.size() < 1)
          {
            break;
          }
          std::cout << " you have the following items in your inventory " << std::endl;
          for(int jj=0; jj<(long)itemName.size(); ++jj)
          {
            std::cout << " Index: " << jj << " | Name: " << itemName.at(jj) << " | Quantity: " << itemQuantity.at(jj) << " | Description: " << itemDescription.at(jj) << std::endl;
        std::cout << std::endl;
          }
          do
          {
            std::cout << " which item would you like to sell? please indicate the index number " << std::endl;
            std::cout << "  --------- enter '-1' to cancel action and return to main menu " << std::endl;
            std::cin >> insideAnswer1;
            if(insideAnswer1 == -1)
            {
              break;
            }
            if(insideAnswer1 > itemName.size() || insideAnswer1 > 0)
            {
              std::cout << " your selection is out of range " << std::endl;
            }
          }while(insideAnswer1 > itemName.size() || insideAnswer1 < 0);
          if(insideAnswer1 == -1)
          {
            break;
          }
          std::cout << " you're about to sell :: " << itemName.at(insideAnswer1) << std::endl;
          std::cout << " how many " << itemName.at(insideAnswer1) << std::endl;
          std::cout << " -----enter '-1' to return to main menu " << std::endl;
          do
          {
            std::cin >> insideAnswer2;
            if(insideAnswer2 == -1)
            {
              break;
            }
            if(insideAnswer2 <= itemQuantity.at(insideAnswer1))
            {
              allGood = true;
            }
            else
            {
              std::cout << " you do not have that much " << std::endl;
            }
          }while(allGood != true);
          if(insideAnswer2 == -1)
          {
            break;
          }
          std::cout << " how many starCoins does your item cost each? " << std::endl;
          std::cout << " -----enter '-1' to return to main menu " << std::endl;
          std::cin >> insideAnswer3;
          if(insideAnswer3 == -1)
          {
            break;
          }
          std::cout << " you are selling " << insideAnswer2 << " :: " << itemName.at(insideAnswer1) << " for " << insideAnswer3 << " starCoins " << std::endl;
        
          //fill in the order book
        
          //the owner of the sale
          lineOwner.push_back(aliasVector.at(0));

          //add the name of the item to the list of sales
          itemNames.push_back(itemName.at(insideAnswer1));
        

          //add the item's description
          itemDescriptions.push_back(itemDescription.at(insideAnswer1));

          //add the amount of quantity to be sold here
          itemQuantities.push_back(insideAnswer2);

          //subtract from the owned amount
          itemQuantity.at(insideAnswer1) -= insideAnswer2;


          //add to the status for sale quantity
          saleQuantity.at(insideAnswer1) += insideAnswer2;

          //add the price to the list
          itemPrice.push_back(insideAnswer3);

        /* so the item list has the same index in the vector so the name, quantity sold, description,
           price, and owner are each stored in the same index of a vector.
        */
          break;
        
      //buy item from available list
      case 5:
        std::cout << std::endl;
        std::cout << " Welcome this is the list of items available for query " << std::endl;
        for(long long i=0; i<(long)itemPrice.size(); ++i)
        {
          std::cout << " Index: " << i << " | Name: " << itemNames[i] << " | Quantity: " << itemQuantities[i] << " | Price: " << itemPrice[i] << " | Description: " << itemDescriptions[i] << " | Seller Alias: " << lineOwner.at(i) << std::endl;
        }
        std::cout << " which item would you like to buy ? " << std::endl;
        std::cout << " Indicate the index value " << std::endl;
        std::cout << " -----enter '-1' to return to main menu " << std::endl;
        std::cin >> insideAnswer2;
        if(insideAnswer2 == -1)
        {
          break;
        }
        std::cout << " you have chosen " << std::endl; 
        std::cout << " Index: " << insideAnswer2 << " |Name: " << itemNames[insideAnswer2] << " |Available Quantity: " << itemQuantities[insideAnswer2] << " |At Price: " << itemPrice[insideAnswer2] << std::endl;
        std::cout << " how much of this would you like to buy? " << std::endl;
        std::cout << " -----enter '-1' to return to main menu " << std::endl;
        do
        {
          std::cin >> insideAnswer1;
          if(insideAnswer1 == -1)
          {
            break;
          }
          if((insideAnswer1 * itemPrice[insideAnswer2]) >= starCoins)
          {
            std::cout << " you have insufficient balance for this purchase " << std::endl;
            goodBalance = false;
          }
          //check if they can afford this item
          //if they can check if there is enough available to be bought
          //so multiply quantity by price and see if there is enough starCoins in the balance
          if(insideAnswer1 > itemQuantities[insideAnswer2])
          {
            std::cout << " you are trying to buy more than is available " << std::endl;
            goodBalance = false;
          }
          if(insideAnswer1 <= itemQuantities[insideAnswer2] && (insideAnswer1 * itemPrice[insideAnswer2] <= starCoins))
          {
            goodBalance = true;
          }
        }while(goodBalance == false);
        if(insideAnswer1 == -1)
        {
          break;
        }
        starCoins -= (insideAnswer1 * itemPrice[insideAnswer2]);
        std::cout << " your remaining starCoin balance: " << starCoins << std::endl;
        
        //deduct from the sale item list once an item is bought
        itemQuantities[insideAnswer2] -= insideAnswer1;
        itemName.push_back(itemNames[insideAnswer2]);
        itemDescription.push_back(itemDescriptions[insideAnswer2]);
        itemQuantity.push_back(insideAnswer1);
        break;

        //view items for sale owned by the user
      case 6:
        for(long long ii=0; ii<(long)itemPrice.size(); ++ii)
        {
          if(lineOwner.at(ii) == aliasVector.at(3))
          {
            std::cout << " Index: " << ii <<  " | Name: " << itemNames.at(ii) << " | Quantity: " << itemQuantities.at(ii) << " | Price: " << itemPrice.at(ii) << std::endl;
          }
        }
        std::cout << " 1. to cancel an order " << std::endl;
        std::cout << " 2. to change the quantity of an order " << std::endl;
        std::cout << " 3. to change the price of an order " << std::endl;
        std::cout << " 4. home menu " << std::endl;
        std::cin >> insideAnswer1;
          switch(insideAnswer1)
          {
            case 1:
              std::cout << " which index number would you like to clear off? " << std::endl;
              std::cout << " -----enter '-1' to return to main menu " << std::endl;
              std::cin >> insideAnswer1;
              if(insideAnswer1 == -1)
              {
                break;
              }
              lineOwner.erase(lineOwner.begin() + insideAnswer1);
              itemNames.erase(itemNames.begin() + insideAnswer1);
              itemQuantities.erase(itemQuantities.begin() + insideAnswer1);
              itemDescriptions.erase(itemDescriptions.begin() + insideAnswer1);
              itemPrice.erase(itemPrice.begin() + insideAnswer1);
              break;
            case 2: 
              std::cout << " which index number would you like to alter the quantity " << std::endl;
              std::cout << " -----enter '-1' to return to main menu " << std::endl;
              std::cin >> insideAnswer1;
              if(insideAnswer1 == -1)
              {
                break;
              }
              std::cout << " the current quantity " << itemQuantities[insideAnswer1] << " | of " << itemNames[insideAnswer1] << std::endl;
              std::cout << " please specify what amount you would like to change your order to? " << std::endl;
              std::cout << " you have " << itemQuantity[insideAnswer1] <<  " remaining in your inventory " << std::endl;
              std::cout << " -----enter '-1' to return to main menu " << std::endl;
              std::cin >> insideAnswer2;
              if(insideAnswer2 == -1)
              {
                break;
              }
              //add validator for itemName and item quantity
              for(long long ii = 0; ii<(long)itemName.size(); ++ii)
              {
                if(itemName[ii] == itemNames[insideAnswer1])
                {
                  if(itemQuantity[ii] >= insideAnswer2)
                  {
                    saleQuantity[ii] -= itemQuantities[insideAnswer1];
                    saleQuantity[ii] += insideAnswer2;
                    itemQuantity[ii] += itemQuantities[insideAnswer1];
                    itemQuantities[insideAnswer1] = insideAnswer2;
                    itemQuantity[ii] -= insideAnswer2;
                  }
                }
              }
              break;
            case 3:
              std::cout << " which index number would you like to alter the price " << std::endl;
              std::cout << " -----enter '-1' to return to main menu " << std::endl;
              std::cin >> insideAnswer1;
              if(insideAnswer1 == -1)
              {
                break;
              }
              std::cout << " the current price " << itemPrice[insideAnswer1] << " | for " << itemNames[insideAnswer1] << std::endl;
              std::cout << " please specify the price you would like to change your order to " << std::endl;
              std::cout << " -----enter '-1' to return to main menu " << std::endl;
              std::cin >> insideAnswer2;
              if(insideAnswer2 == -1)
              {
                break;
              }
              for(long long jj=0; jj<(long)itemNames.size(); ++jj)
              {
                if(lineOwner[jj] == aliasVector[0])
                {
                  itemPrice[insideAnswer1] = insideAnswer2;
                }
              }
              break;
            case 4:
              break;
          }
        break;
    }
  } while(answer !=0);


    return 0;
}


long long answers(long long& answer)
{
  std::cin >> answer;
  return answer;
}
