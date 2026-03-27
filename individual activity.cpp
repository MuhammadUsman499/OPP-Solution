#include <iostream>
using namespace std;
class Hero {
protected:
    string name;
    string type;
    int health;
    double powerLevel;
    int experience;

public:
    Hero(string n, string t, int h, double p, int e) {
    name = n;
    type = t;
    health = h;
    powerLevel = p;
    experience = e;
}
    void showGameMessage() {
        cout << "\n WELCOME TO FANTASY BATTLE ARENA \n";
        cout << "Each hero has unique attack and defense abilities.\n";
        cout << "Let the battle begin"<<endl;
    }

    void displayBasicInfo() {
        cout << "Hero Name: " << name << endl;
        cout << "Hero Type: " << type << endl;
        cout << "Health: " << health << endl;
        cout << "Power Level: " << powerLevel << endl;
        cout << "Experience: " << experience << endl;
    }

    virtual double attack() = 0;
    virtual double defend() = 0;
};



class Warrior : public Hero {
private:
    int armorStrength;
    double rageLevel;
    string weaponName;

public:
    Warrior(string n, int h, double p, int e,string w , int a, double r) : Hero(n, "Warrior", h, p, e) 
{
    weaponName = w ;
    armorStrength = a;
    rageLevel = r;
}

    void display() {
        cout << "\n WARRIOR PROFILE \n";
        displayBasicInfo();
        cout << "Weapon: " << weaponName << endl;
        cout << "Armor Strength: " << armorStrength << endl;
        cout << "Rage Level: " << rageLevel << endl;
    }

    double attack() {
        return powerLevel * 1.5 + rageLevel * 2;
    }

    double defend() {
        return armorStrength * 1.8 + health * 0.2;
    }
};



class Mage : public Hero {
private:
    string spellName;
    int manaPoints;
    double magicMultiplier;

public:
    Mage(string n, int h, double p, int e,string s, int m, double mm): Hero(n, "Mage", h, p, e)
{
    spellName = s;
    manaPoints = m;
    magicMultiplier = mm ;
}

    void display() {
        cout << "\n MAGE PROFILE \n";
        displayBasicInfo();
        cout << "Spell: " << spellName << endl;
        cout << "Mana Points: " << manaPoints << endl;
        cout << "Magic Multiplier: " << magicMultiplier << endl;
    }

    double attack() {
        return powerLevel * magicMultiplier + manaPoints * 1.2;
    }

    double defend() {
        return manaPoints * 1.5 + health * 0.1;
    }
};



class Archer : public Hero {
private:
    string bowType;
    int arrows;
    double accuracy;

public:
    Archer(string n, int h, double p, int e,string b, int a, double acc): Hero(n, "Archer", h, p, e)
{
    bowType = b;
    arrows = a;
    accuracy = acc;
}

    void display() {
        cout << "\n ARCHER PROFILE \n";
        displayBasicInfo();
        cout << "Bow Type: " << bowType << endl;
        cout << "Arrows: " << arrows << endl;
        cout << "Accuracy: " << accuracy << endl;
    }

    double attack() {
        return powerLevel * accuracy + arrows * 0.5;
    }

    double defend() {
        return accuracy * 2 + health * 0.15;
    }
};



int main() {

    Warrior w ("Thor", 150, 80.5, 50, "Axe", 70, 40.5);
    Mage m("Merlin", 100, 90.0, 60, "Fireball", 120, 2.5);
    Archer a("Robin", 110, 75.0, 45, "Longbow", 60, 1.8);

    w.showGameMessage();

    
    w.display();
    m.display();
    a.display();

    // Attack & Defense
    double wAtk = w.attack();
    double wDef = w.defend();

    double mAtk = m.attack();
    double mDef = m.defend();

    double aAtk = a.attack();
    double aDef = a.defend();

    cout << "\n _______BATTLE RESULTS_______ \n";

    cout << "\nWarrior Attack: " << wAtk;
    cout << "\nWarrior Defense: " << wDef;

    cout << "\n\nMage Attack: " << mAtk;
    cout << "\nMage Defense: " << mDef;

    cout << "\n\nArcher Attack: " << aAtk;
    cout << "\nArcher Defense: " << aDef;
    
    

    // Summary
    cout << "\n\n ______SUMMARY_______ \n";

    double maxAttack = wAtk;
    string bestHero = "Warrior";

    if (mAtk > maxAttack) {
        maxAttack = mAtk;
        bestHero = "Mage";
    }

    if (aAtk > maxAttack) {
        maxAttack = aAtk;
        bestHero = "Archer";
    }

    cout << "Highest Attack Hero: " << bestHero << endl;
    cout << "Attack Value: " << maxAttack << endl;

    return 0;
}
