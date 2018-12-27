#include <iostream>

#include <vector>
using namespace std;

namespace Product
{
	namespace Parts
	{
		class Vehicle
		{
			public :
				string type;
		};
			
		class Clan
		{
			public :
				string clan;
		};

		class Weapons
		{
			public :
				vector <string> list;
		};

	}
	
	class Transformer
	{
		public :
			Parts :: Vehicle * ptrVehicle;
			Parts :: Clan * ptrClan;
			Parts :: Weapons * ptrWeapons;

			void getSpecs()
			{
				cout << "Vehicle    : "<< ptrVehicle -> type << endl;  
				cout << "Clan       : "<< ptrClan -> clan << endl;
				cout << "Weapons    : ";
				for (auto it : ptrWeapons->list) { cout << it << ", "; }
				cout << endl;
				
			}
	};
}

namespace Builder
{
	class Engineer
		{
			public :
				virtual Product :: Parts :: Vehicle * getVehicle() = 0;
				virtual Product :: Parts :: Clan * getClan() = 0;
				virtual Product :: Parts :: Weapons * getWeapons() = 0;
		};

	class OptimusPrimeEngine : public Engineer
		{
			public :
				Product :: Parts :: Vehicle * getVehicle() 
				{
					Product :: Parts :: Vehicle * ptrVehicle = new Product :: Parts :: Vehicle();
					ptrVehicle -> type = "Truck";
					return ptrVehicle;	
				}

				Product :: Parts :: Clan * getClan() 
				{
					Product :: Parts :: Clan * ptrClan = new Product :: Parts :: Clan();
					ptrClan -> clan = "AutoBots";
					return ptrClan;
				}

				Product :: Parts :: Weapons * getWeapons() 
				{
					Product :: Parts :: Weapons * ptrWeapons = new Product :: Parts :: Weapons();
					ptrWeapons -> list.push_back("Sword");
					ptrWeapons -> list.push_back("Blaster");
					ptrWeapons -> list.push_back("Rocket_Booster");
					ptrWeapons -> list.push_back("Guns");
					ptrWeapons -> list.push_back("Rope");
					return ptrWeapons;	
				}
		};

	class MegatronEngine : public Engineer
		{
			public :
				Product :: Parts :: Vehicle * getVehicle() 
				{
					Product :: Parts :: Vehicle * ptrVehicle = new Product :: Parts :: Vehicle();
					ptrVehicle -> type = "Aeroplane";
					return ptrVehicle;	
				}

				Product :: Parts :: Clan * getClan() 
				{
					Product :: Parts :: Clan * ptrClan = new Product :: Parts :: Clan();
					ptrClan -> clan = "Decepticons";
					return ptrClan;
				}

				Product :: Parts :: Weapons * getWeapons() 
				{
					Product :: Parts :: Weapons * ptrWeapons = new Product :: Parts :: Weapons();
					ptrWeapons -> list.push_back("Blaster");
					ptrWeapons -> list.push_back("Guns");
					return ptrWeapons;	
				}
		};
}

class Director
{
	protected :
		Builder :: Engineer * ptrEngineer;

	public :
		void setEngineer(Builder :: Engineer * ptrEngineer) {this -> ptrEngineer = ptrEngineer;}
		Product :: Transformer * getSpecs()
		{
			Product :: Transformer * ptrTransformer = new Product :: Transformer();
			ptrTransformer -> ptrVehicle = this -> ptrEngineer -> getVehicle();
			ptrTransformer -> ptrClan = this -> ptrEngineer -> getClan();
			ptrTransformer -> ptrWeapons = this -> ptrEngineer -> getWeapons();
			return ptrTransformer;
		}
};

int main()
{
	Product :: Transformer * ptrTransformer;
	Director ObjDirector;

	Builder :: OptimusPrimeEngine ObjOptimusPrime;
	Builder :: MegatronEngine ObjMegatron;

	cout << "Optimus Prime" << endl;
	ObjDirector.setEngineer(&ObjOptimusPrime);
	ptrTransformer = ObjDirector.getSpecs();
	ptrTransformer -> getSpecs();

	cout << endl;

	cout << "Megatron" << endl;
	ObjDirector.setEngineer(&ObjMegatron);
	ptrTransformer = ObjDirector.getSpecs();
	ptrTransformer -> getSpecs();
	
     	return 0;
}
