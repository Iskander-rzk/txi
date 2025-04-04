#include <iostream>
#include <string>
#include <vector>

class Weapon {
protected:
    std::string Brand;
public:
    Weapon(const std::string& brand) : Brand(brand) {}
    virtual void ShowInfo() const {
        std::cout << "Brand: " << Brand << std::endl; 
    }
    virtual ~Weapon() {}
};

class Firearm : public Weapon {
protected:
    std::string Category; // 0 - automatic, 1 - semi-auto, 2 - burst, 3 - etc.
public:
    Firearm(const std::string& brand, const std::string& category) : Weapon(brand), Category(category) {}
    void ShowInfo() const override {
        std::cout << "Weapon Type: " << Brand << ", Category: " << Category << std::endl; 
    }
};

class AssaultRifle : public Firearm {
private:
    int Caliber;
public:
    AssaultRifle(const std::string& brand, const std::string& category, int caliber) 
        : Firearm(brand, category), Caliber(caliber) {}
    void ShowInfo() const override {
        std::cout << "Assault Rifle Brand: " << Brand << ", Category: " << Category 
                  << ", Caliber: " << Caliber << " mm" << std::endl;
    }
};

class MachineGun : public Firearm {
private:
    int BeltCapacity;
    int Caliber;
public:
    MachineGun(const std::string& brand, const std::string& category, int caliber, int capacity) 
        : Firearm(brand, category), Caliber(caliber), BeltCapacity(capacity) {}
    void ShowInfo() const override {
        std::cout << "Machine Gun Brand: " << Brand << ", Category: " << Category 
                  << ", Caliber: " << Caliber << " mm, Belt Capacity: " 
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
    SniperRifle(const std::string& brand, const std::string& category, int caliber, int maxDistance, Sniper* sniper) 
        : Firearm(brand, category), Caliber(caliber), MaxDistance(maxDistance), _Sniper(sniper) {}
    void ShowInfo() const override {
        std::cout << "Sniper Rifle Brand: " << Brand << ", Category: " << Category 
                  << ", Caliber: " << Caliber << " mm, Max Distance: " << MaxDistance 
                  << " meters, Sniper: " << _Sniper->GetName() << std::endl;
    }
};

int main() {
    Weapon car("Toyota");
    AssaultRifle scar("SCAR", "automatic", 556);
    Sniper john("John Doe");
    SniperRifle barret("Barrett", "bolt-action", 50, 1500, &john);

    car.ShowInfo();
    scar.ShowInfo();
    barret.ShowInfo();
    
    return 0;
}