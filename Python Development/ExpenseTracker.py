print("Hello! Welcome to the Expense Tracker!\n")
print("To record an expense, type 'R'.\nTo delete an expense, type 'D'.\nTo view all expenses, type 'V'")

expenses = []

#Loops forever
while (True):
    
    choice = input("\nWhat would you like to do: ")
    print("\n")
    
    #Allow users to pick what they would like to do.
    if (choice == "R" or choice == "r"):

        name = input("Please enter the name of the expense:")
        cost = input("Please enter the cost of the expense:")
        category = input("Please enter the category of the expense:")
    
        expenses.append(tuple([name,cost,category]))
        
        print("Recorded!")
        
    elif (choice == "D" or choice == "d"):    
        
        #Checks if there are any entries prior to attempting to delete.
        if (len(expenses)!=0):
            
            #Display entries first
            count = 0
            for item in expenses:
                print(str(count) + " : " + str(item))
                count+=1
                
            delete = int(input("\nPlease type the number of the expense you would like to delete (Starts at 0):"))

            if (delete >= len(expenses)):
                print("There is no expense at that number.\n")

            else:
                del expenses[delete]
                print("\nDeleted!")
        
        else: 
            print("There are no recorded expenses yet.\n")

    elif (choice == "V" or choice == "v"):
        
        count = 0
        
        #Checks if there are any entries prior to attempting to view.
        if (len(expenses)!=0):
         
            #Prints every tuple in the array on seperate lines
            for item in expenses:
                print(str(count) + " : " + str(item))
                count+=1

        else: 
            print("There are no recorded expenses.\n")
    
    else:
        print("Invalid response. Please try again.")



