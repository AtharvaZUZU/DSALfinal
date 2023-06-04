def menu():
	print("-------------------------------")
	print("Set Theory")
	print("-------------------------------")
	print("1.Add Element")
	print("2.Delete Element")
	print("3.Search Element")
	print("4.Display")
	print("5.Union")
	print("6.Intersection")
	print("7.Difference")
	print("8.Exit")
	print("Enter Your Choice:")
	
def takeinput(set):
	size= int(input(f"enter the size of set {set}: "))
	a=[]
	for i in range(0,size):
		a.append(int(input("enter elements: ")))
	return a
	
a = takeinput("A")
b = takeinput("B")	

def intersection(L1,L2):
	res=[]
	
	for stud in L1:
		if stud in L2:
			res.append(stud)
	return res
	
def union(L1,L2):
	res=L2.copy()
	
	for stud in L1:
		if not stud in L2:
			res.append(stud)
	return res
	
def diff(L1,L2):
	res=[]
	for stud in L2:
		if not stud in L2:
			res.append(stud)
	return res

def switch(ch):
	
    if ch == 1:
        add=input("which set you want to select A/B : ")
        if add == "A":
            num=int(input("enter element to add in A : "))
            if num not in a:
                a.append(num)
                print("A: ",a)
        
        elif add == "B":
            num=int(input("enter element to add in B : "))
            if num not in b:
                b.append(num)
                print("B: ",b)
        else:
            print("Enter a valid set")  

    elif ch == 2:
        dele=input("which set you want to select A/B : ")
        if dele == "A":
            num=int(input("enter element to delete from A : "))
            if num in a:
                a.remove(num)
                print("A: ",a)
        
        elif dele == "B":
            num=int(input("enter element to delete from B : "))
            if num in b:
                b.remove(num)
                print("B: ",b)
        else:
            print("Enter a valid set")
            
    elif ch == 3:
        num=int(input("enter element to search : "))
        if num in a:
            print("the number is present in set A")
        elif num in b:
            print("the number is present in set B")
        else:
            print("the number is not present in either of the sets") 

    elif ch == 4:
        print("Both sets contains")
        print("A: ",a)
        print("B: ",b)
    elif ch == 5:
        print("union of A and B is")
        print(union(a,b))
    elif ch == 6:
        print("intersection of A and B is")
        print(intersection(a,b))
    elif ch == 7:
        print("difference of A and B is")
        print(diff(a,b))
    elif ch == 8:
        print("exiting......")
    else:
        print("This is the default case")


while(1):
    menu()
    ch=int(input())
    switch(ch)
    if ch ==8:
	    break