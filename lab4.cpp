#include <iostream>
#include <string>
#include <vector>

class Weapon {
protected:
    std::string Brand;
    int Cost;
public:
    Weapon(const std::string& brand, int cost) : Brand(brand, cost) {}
    virtual void ShowInfo() const {
        std::cout << "Brand: " << Brand << " " <<  Cost << "$" << std::endl ; 
    }
    
    void HelloWorld()  {
        std::cout << "Hello World!";
    }
    virtual ~Weapon() {}
};

class Firearm : public Weapon {
protected:
    std::string Category; 
public:
    Firearm(const std::string& brand, int cost, const std::string& category) : Weapon(brand, cost), Category(category) {}
    void ShowInfo() const override {
        std::cout << "Weapon Type: " << Brand << ", Category: " << Category << " " <<  Cost << "$" << std::endl; 
    }
};

class AssaultRifle : public Firearm {
private:
    int Caliber;
public:
    AssaultRifle(const std::string& brand, int cost, const std::string& category, int caliber) 
        : Firearm(brand, cost, category), Caliber(caliber) {}
    void ShowInfo() const override {
        std::cout << "Assault Rifle Brand: " << Brand << ", Category: " << Category 
                  << ", Caliber: " << Caliber << " mm" << " " <<  Cost << "$" << std::endl;
    }
    void HelloWorld()  {
        std::cout << "Hello World!";
    }
};

class MachineGun : public Firearm {
private:
    int BeltCapacity;
    int Caliber;
public:
    MachineGun(const std::string& brand, int cost, const std::string& category, int caliber, int capacity) 
        : Firearm(brand, cost, category), Caliber(caliber), BeltCapacity(capacity) {}
    void ShowInfo() const override {
        std::cout << "Machine Gun Brand: " << Brand << ", Category: " << Category 
                  << ", Caliber: " << Caliber << " mm, Belt Capacity: " " " <<  Cost << "$" 
                  << BeltCapacity << " rounds" << std::endl;
    }
};

class Sniper {
private:
    std::string Name;
public:
    Sniper(const std::string& name) : Name(name) {}
    std::string GetName() const { return Name; }
};

class SniperRifle : public Firearm {
private:
    Sniper* _Sniper;
    int MaxDistance;
    int Caliber;
public:
    SniperRifle(const std::string& brand, int cost, const std::string& category, int caliber, int maxDistance, Sniper* sniper) 
        : Firearm(brand, cost, category), Caliber(caliber), MaxDistance(maxDistance), _Sniper(sniper) {}
    void ShowInfo() const override {
        std::cout << "Sniper Rifle Brand: " << Brand << ", Category: " << " " <<  Cost << "$" << Category 
                  << ", Caliber: " << Caliber << " mm, Max Distance: " << MaxDistance 
                  << " meters, Sniper: " << _Sniper->GetName() << std::endl;
    }
};

int main() {
    Weapon cold("Katana", 500);
    AssaultRifle scar("SCAR", 2500, "automatic", 556);
    Sniper john("John Doe");
    SniperRifle barret("Barrett", 4000, "bolt-action", 50, 1500, &john);
    Weapon* rifle = &scar;
    cold.ShowInfo();
    scar.ShowInfo();
    barret.ShowInfo();
    rifle->ShowInfo();
    rifle->HelloWorld();
    return 0;
} 