/*
Lesson 7.4 Samples Methods
Pawelski
5/19/2021
In this sample, I provide a finished class.
*/
#include <iostream>
using namespace std;

class Dog
{
private:
    string name;
    int age;
    double weight;
    string breed;

public:
    Dog(string name, int age, double weight, string breed)
    {
        this->name = name;
        this->age = age;
        this->weight = weight;
        this->breed = breed;
    }

    /*
    The following four methods are accessors!
    */
    string getName()
    {
        return name;
    }

    int getAge()
    {
        return age;
    }

    double getWeight()
    {
        return weight;
    }

    string getBreed()
    {
        return breed;
    }

    /*
    The following four methods are mutators!
    */
    void setName(string name)
    {
        this->name = name;
    }

    /*
    This particular method is special as a dog
    cannot decrease in age. Consequently, the mutator
    checks if the new age is greater than or equal to
    to old age. If it is, the age is updated and true
    is returned. If it is not, the age is not updated
    and false is returned.
    */
    bool setAge(int age)
    {
        if (age >= this->age)
        {
            this->age = age;
            return true;
        }
        return false;
    }

    void setWeight(double weight)
    {
        this->weight = weight;
    }

    void setBreed(string breed)
    {
        this->breed = breed;
    }

    /*
    Here are other methods for the class. These
    do not fall under the mutator or accessor
    categories.
    */
    void bark()
    {
        cout << "woof, woof" << "\n";
    }

    /*
    This method is special as it shows how methods within
    a class can directly call each other without having to
    create an object!
    */
    bool checkup(int age, double weight)
    {
        setWeight(weight);
        return setAge(age);
    }

    void print()
    {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Weight: " << weight << "\n";
        cout << "Breed: " << breed << "\n";
    }

    /*
    Duration represents the number of minutes the
    tunderstorm will last.
    */
    void thunderstorm(int duration)
    {
        for (int i = 0; i < duration; i++)
        {
            bark();
        }
    }
};

int main()
{
    /*
    This is the client code that creates an object from
    the Dog class. Notice how we call methods and don't
    have direct access to the instance variables. Instead,
    we need to use accessor and mutator methods!
    */
    Dog d("Beethoven", 5, 165.2, "St. Bernard");
    d.print();
    cout << "\n";
    d.bark();
    cout << "\n";
    cout << d.setAge(6) << "\n";
    cout << d.setAge(2) << "\n\n";
    cout << d.getAge() << "\n\n";

    int age;
    cout << "What is the new age of the dog? >> ";
    cin >> age;
    if (d.setAge(age))
    {
        cout << "Age successfully updated!\n";
    }
    else
    {
        cout << "Could not update age!\n";
    }
    cout << "\n";

    d.thunderstorm(120);
    return 0;
}
