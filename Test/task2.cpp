// Eng_float.cpp

#include <iostream>

class Distance 
{
private:
    const float MTF;
    int feet;
    float inches;

public:
    Distance() : MTF(3.280833F), feet(0), inches(0.0F) { std::cout << "\nDefault constructor\n"; }

    Distance(float meters) : MTF(3.280833F)
    {
        float fltfeet = MTF * meters;
        feet = int(fltfeet);
        inches = 12.0F * (fltfeet - feet);
        std::cout << "\nSingle-argument constructor (meters)\n";
    }

    Distance(int ft, float in) : MTF(3.280833F), feet(ft), inches(in) { }

    void getdist()
    {
        std::cout << "\nEnter feet: ";  std::cin >> feet;
        std::cout << "Enter inches: ";  std::cin >> inches;
    }

    void showdist() const
    {
        std::cout << feet << "\'-" << inches << '\"';
    }

    Distance operator+(Distance) const;

    /*explicit*/ operator float() const
    {
        float fracfeet = inches / 12.0F;
        fracfeet += static_cast<float>(feet);
        return fracfeet / MTF;
    }

    // Assign from another Distance (copy feet inches const MTF) overloaded
    Distance& operator=(const Distance& rhs)
    {
        if (this != &rhs)
        {
            this->feet = rhs.feet;
            this->inches = rhs.inches;
        }
        return *this;
    }

    // Assign from meters (float) overloaded
    Distance& operator=(float meters)
    {
        float fltfeet = MTF * meters;
        this->feet = int(fltfeet);
        this->inches = 12.0F * (fltfeet - this->feet);
        return *this;
    }
};

Distance Distance::operator+(Distance d2) const
{
    int f = feet + d2.feet;
    float i = inches + d2.inches;
    if (i >= 12.0F)
    {
        i -= 12.0F;
        f++;
    }
    return Distance(f, i);
}

int main()
{
    float mtrs;
    Distance dist1 = 2.35F; // uses meters -> feet inches constructor

    Distance dist101;
    std::cout << "\ndist101 = ";
    dist101.showdist();

    dist101 = 2.22F;  // assignment uses operator=(float)
    std::cout << "\nAfter 'dist101 = 2.22F' => dist101 = ";
    dist101.showdist();

    std::cout << "\n\ndist1 = ";
    dist1.showdist();

    std::cout << "\n\ndist101 = ";
    dist101.showdist();

    mtrs = static_cast<float>(dist1);
    std::cout << "\n\ndist1 = " << mtrs << " meters\n";

    Distance dist2(5, 10.25F);

    mtrs = dist2; 
    std::cout << "\ndist2 = " << mtrs << " meters\n";

    dist2 = mtrs;  // assignment uses operator=(float)
    std::cout << "After 'dist2 = mtrs' => dist2 = ";
    dist2.showdist();
    std::cout << '\n';

    Distance dist3;
    dist3 = dist1; // assignment uses operator=(const Distance&)
    std::cout << "\nAfter 'dist3 = dist1' => dist3 = ";
    dist3.showdist();
    std::cout << '\n';

    Distance dist11 = dist1 + dist2;

    std::cout << "\n\ndist11 = ";
    dist11.showdist();
    std::cout << '\n';

    return 0;
}
