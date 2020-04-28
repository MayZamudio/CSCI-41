#include <iostream>
#include <stdexcept>
using namespace std;

//This final homework assignment will teach you:
//Inheritance (polymorphism)
//Bit fields
//Refresher on overloading operators
//Three different ways of doing constants
//A bit of exceptions
//These constants can either be accessed by name "orange" or by "key_colors::orange" for clarity
enum key_colors {
	red = 1,
	yellow = 2,
	green = 4,
	blue = 8,
	orange = 16,
	ultraviolet = 32,
	brown = 64,
	black = 128
};
/*string string_to_key(int64_t flag) {
	if (flag == red) return "RED";
	throw runtime_error("bad int to string");
}*/

int64_t string_to_key(string s) {
	if (s == "RED") return key_colors::red;
	if (s == "YELLOW") return key_colors::yellow;
	if (s == "GREEN") return key_colors::green;
	if (s == "BLUE") return key_colors::blue;
	if (s == "ORANGE") return key_colors::orange;
	if (s == "ULTRAVIOLET") return key_colors::ultraviolet;
	if (s == "BROWN") return key_colors::brown;
	if (s == "BLACK") return key_colors::black;
	throw runtime_error("Bad color passed");
}

//The player can only have one of this list of bits set between JOB_THIEF and JOB_PSION
//Setting another bit in this range will clear all the other bits in the range set
const int JOB_THIEF  = 1;
const int JOB_RUNNER = 2;
const int JOB_WARLOCK = 4;
const int JOB_CHAPLAN = 8;
const int JOB_BERSERKER = 16;
const int JOB_GUERILLA = 32;
const int JOB_JUDOKA = 64;
const int JOB_ARMY = 128;
const int JOB_HACKER = 256;
const int JOB_MARTYR = 512;
const int JOB_CRUSADER = 1024;
const int JOB_TKD = 262144;
const int JOB_PSION = 524288;

const int JOB_ALL = 788479; //The sum of all bits above, for easy math

//Any or all of these can be set in addition to the above
const int JOB_ACTIVE = 2048;
const int JOB_FULL_HIDE = 4096;
const int JOB_TIRED = 8192;
const int JOB_BLOODY_KNIFE = 16384;
const int JOB_EXTRA1 =		65536;
const int JOB_EXTRA2 =		131072;

string job_to_string(int64_t flag) {
	if (flag == JOB_ALL) return "JOB_ALL";
	if (flag == JOB_ARMY) return "JOB_ARMY";
	if (flag == JOB_ACTIVE) return "JOB_ACTIVE";
	if (flag == JOB_BERSERKER) return "JOB_BERSERKER";
	if (flag == JOB_BLOODY_KNIFE) return "JOB_BLOODY_KNIFE";
	if (flag == JOB_CHAPLAN) return "JOB_CHAPLAN";
	if (flag == JOB_CRUSADER) return "JOB_CRUSADER";
	if (flag == JOB_GUERILLA) return "JOB_GUERILLA";
	if (flag == JOB_HACKER) return "JOB_HACKER";
	if (flag == JOB_JUDOKA) return "JOB_JUDOKA";
	if (flag == JOB_MARTYR) return "JOB_MARTYR";
	if (flag == JOB_PSION) return "JOB_PSION";
	if (flag == JOB_RUNNER) return "JOB_RUNNER";
	if (flag == JOB_WARLOCK) return "JOB_WARLOCK";
	if (flag == JOB_EXTRA1) return "JOB_EXTRA1";
	if (flag == JOB_EXTRA2) return "JOB_EXTRA2";
	if (flag == JOB_FULL_HIDE) return "JOB_FULL_HIDE";
	if (flag == JOB_TIRED) return "JOB_TIRED";
	if (flag == JOB_THIEF) return "JOB_THIEF";
	if (flag == JOB_TKD) return "JOB_TKD";
	throw runtime_error("Bad job to string passed");
}


int64_t string_to_job(string s) {
	if (s == "JOB_ALL") return JOB_ALL;
	if (s == "JOB_ARMY") return JOB_ARMY;
	if (s == "JOB_ACTIVE") return JOB_ACTIVE;
	if (s == "JOB_BERSERKER") return JOB_BERSERKER;
	if (s == "JOB_BLOODY_KNIFE") return JOB_BLOODY_KNIFE;
	if (s == "JOB_CHAPLAN") return JOB_CHAPLAN;
	if (s == "JOB_CRUSADER") return JOB_CRUSADER;
	if (s == "JOB_GUERILLA") return JOB_GUERILLA;
	if (s == "JOB_HACKER") return JOB_HACKER;
	if (s == "JOB_JUDOKA") return JOB_JUDOKA;
	if (s == "JOB_MARTYR") return JOB_MARTYR;
	if (s == "JOB_PSION") return JOB_PSION;
	if (s == "JOB_RUNNER") return JOB_RUNNER;
	if (s == "JOB_WARLOCK") return JOB_WARLOCK;
	if (s == "JOB_EXTRA1") return JOB_EXTRA1;
	if (s == "JOB_EXTRA2") return JOB_EXTRA2;
	if (s == "JOB_FULL_HIDE") return JOB_FULL_HIDE;
	if (s == "JOB_TIRED") return JOB_TIRED;
	if (s == "JOB_THIEF") return JOB_THIEF;
	if (s == "JOB_TKD") return JOB_TKD;
	throw runtime_error("Bad job passed to string_to_job");
}




//This is the C way of doing constants
#define WEAP_HOOK				1
#define WEAP_THE_NAVARRO        2
#define WEAP_MEDIKIT			4
#define WEAP_SPANNER			8
#define WEAP_AXE				16
#define WEAP_SNIPER_RIFLE		32
#define WEAP_AUTO_RIFLE 		64
#define WEAP_SHOTGUN			128
#define WEAP_SUPER_SHOTGUN		256
#define WEAP_NAILGUN			512
#define WEAP_LIGHT_ASSAULT		1024
#define WEAP_GRENADE_LAUNCHER	2048
#define WEAP_FLAMETHROWER		4096
#define WEAP_ROCKET_LAUNCHER	8192
#define WEAP_INCENDIARY 		16384
#define WEAP_ASSAULT_CANNON 	32768
#define WEAP_LIGHTNING			65536
#define WEAP_DAEDALUS			131072
#define WEAP_TRANQ				262144
#define WEAP_RAILGUN			524288
#define WEAP_MAUSER 			1048576
#define WEAP_AIRFIST			2097152
#define WEAP_LASERCANNON		4194304
#define WEAP_SNG				8388608

string weapon_to_string(int64_t flag) {
	if (flag == WEAP_HOOK) return "WEAP_HOOK";
	if (flag == WEAP_THE_NAVARRO) return "WEAP_THE_NAVARRO";
	if (flag == WEAP_MEDIKIT) return "WEAP_MEDIKIT";
	if (flag == WEAP_SPANNER) return "WEAP_SPANNER";
	if (flag == WEAP_AXE) return "WEAP_AXE";
	if (flag == WEAP_SNIPER_RIFLE) return "WEAP_SNIPER_RIFLE";
	if (flag == WEAP_AUTO_RIFLE) return "WEAP_AUTO_RIFLE";
	if (flag == WEAP_SHOTGUN) return "WEAP_SHOTGUN";
	if (flag == WEAP_SUPER_SHOTGUN) return "WEAP_SUPER_SHOTGUN";
	if (flag == WEAP_NAILGUN) return "WEAP_NAILGUN";
	if (flag == WEAP_LIGHT_ASSAULT) return "WEAP_LIGHT_ASSAULT";
	if (flag == WEAP_GRENADE_LAUNCHER) return "WEAP_GRENADE_LAUNCHER";
	if (flag == WEAP_FLAMETHROWER) return "WEAP_FLAMETHROWER";
	if (flag == WEAP_ROCKET_LAUNCHER) return "WEAP_ROCKET_LAUNCHER";
	if (flag == WEAP_INCENDIARY) return "WEAP_INCENDIARY";
	if (flag == WEAP_ASSAULT_CANNON) return "WEAP_ASSAULT_CANNON";
	if (flag == WEAP_LIGHTNING) return "WEAP_LIGHTNING";
	if (flag == WEAP_DAEDALUS) return "WEAP_DAEDALUS";
	if (flag == WEAP_TRANQ) return "WEAP_TRANQ";
	if (flag == WEAP_RAILGUN) return "WEAP_RAILGUN";
	if (flag == WEAP_MAUSER) return "WEAP_MAUSER";
	if (flag == WEAP_AIRFIST) return "WEAP_AIRFIST";
	if (flag == WEAP_LASERCANNON) return "WEAP_LASERCANNON";
	if (flag == WEAP_SNG) return "WEAP_SNG";
	throw runtime_error("Something bad happened with: string weapon_to_string(int64_t flag)");
}

int64_t string_to_weapon(string s) {
	if (s == "WEAP_HOOK") return WEAP_HOOK;
	if (s == "WEAP_THE_NAVARRO") return WEAP_THE_NAVARRO;
	if (s == "WEAP_MEDIKIT") return WEAP_MEDIKIT;
	if (s == "WEAP_SPANNER") return WEAP_SPANNER;
	if (s == "WEAP_AXE") return WEAP_AXE;
	if (s == "WEAP_SNIPER_RIFLE") return WEAP_SNIPER_RIFLE;
	if (s == "WEAP_AUTO_RIFLE") return WEAP_AUTO_RIFLE;
	if (s == "WEAP_SHOTGUN") return WEAP_SHOTGUN;
	if (s == "WEAP_SUPER_SHOTGUN") return WEAP_SUPER_SHOTGUN;
	if (s == "WEAP_NAILGUN") return WEAP_NAILGUN;
	if (s == "WEAP_LIGHT_ASSAULT") return WEAP_LIGHT_ASSAULT;
	if (s == "WEAP_GRENADE_LAUNCHER") return WEAP_GRENADE_LAUNCHER;
	if (s == "WEAP_FLAMETHROWER") return WEAP_FLAMETHROWER;
	if (s == "WEAP_ROCKET_LAUNCHER") return WEAP_ROCKET_LAUNCHER;
	if (s == "WEAP_INCENDIARY") return WEAP_INCENDIARY;
	if (s == "WEAP_ASSAULT_CANNON") return WEAP_ASSAULT_CANNON;
	if (s == "WEAP_LIGHTNING") return WEAP_LIGHTNING;
	if (s == "WEAP_DAEDALUS") return WEAP_DAEDALUS;
	if (s == "WEAP_TRANQ") return WEAP_TRANQ;
	if (s == "WEAP_RAILGUN") return WEAP_RAILGUN;
	if (s == "WEAP_MAUSER") return WEAP_MAUSER;
	if (s == "WEAP_AIRFIST") return WEAP_AIRFIST;
	if (s == "WEAP_LASERCANNON") return WEAP_LASERCANNON;
	if (s == "WEAP_SNG") return WEAP_SNG;
	throw runtime_error("Something bad happened with: int64_t string_to_weapon ");
}
typedef int64_t int64; //Here's an example of how to do a typedef

class Bitfield {
  protected: //Protected, not private!!
	int64 datafield;
  public:
	Bitfield() : datafield(0) {}
	//YOU: Set the passed in flag on datafield
	// += operator used to set a bit using the | "or" operator
	void operator+=(const int64_t flag) {
		datafield |= flag;
	}

	/* erase a bit by & "and-ing" it with ~ "not"
	   ie. datafield = 1100
	   	     flag    = 0001
	datafield & flag = 0000
			~flag    = 1110		~ means bitwise NOT
	datafield & ~flag = 1100*/

	void operator-=(const int64_t flag) {
		//YOU: This function will clear the passed in flag
		datafield &= ~flag;
	}

	//YOU: This function will return true if the passed in flag is set
	bool operator==(const int64_t flag) {
		return datafield & flag;
	}
};

class Job_Bitfield : public Bitfield {
  public:
	Job_Bitfield() : Bitfield() {}
	void operator+= (const int64_t flag) {
		if (flag == JOB_ALL) throw runtime_error("Cannot set flag JOB_ALL");
		if (flag & JOB_ALL)
			datafield &= ~JOB_ALL;
		datafield |= flag;
	}
	//YOU: Override the += operator for this class so that it clears any existing jobs between
	// JOB_THIEF and JOB_PSION if a new bit in that range is set.
	//You can use JOB_ALL to quickly test to see if a bit is in that range, and clear all such bits
	// if you do get a match
	//The other bits (JOB_ACTIVE through JOB_EXTRA2) should be left alone and can be independently set
	//JOB_ALL cannot be set by the user. If he tries to, throw a runtime_exception with the string:
	// "Cannot set flag JOB_ALL"
};

class Weapon_Bitfield : public Bitfield {
  public:
	Weapon_Bitfield() : Bitfield() {}
	int64_t select_best_weapon() {
		//YOU: Return the highest bit set

		//If we have no weapon at all, throw an exception
		//Don't bother catching it, we'll let it kill the program
		if (!datafield)
			throw runtime_error("Cannot select best weapon when we don't have one!");
		for (int64_t i = 63; i >= 0 ; i--) {
			int64_t x = 1;
			int64_t flag = x << i;
			if (datafield & flag) return flag;
		}
		throw runtime_error("Logic error!");
	}
};

const int KEYS = 0;
const int JOBS = 1;
const int WEAPONS = 2;

int which_flag(string s) {
	string arg = s.substr(0, 3);
	if (arg == "WEA") return WEAPONS;
	if (arg == "JOB") return JOBS;
	return KEYS;
}

int main() {
	Bitfield keys;
	Job_Bitfield jobs;
	Weapon_Bitfield weapons;

	while (cin) {
		string choice;
		cin >> choice;
		if (!cin) break;
		for (auto &c : choice) c = toupper(c);
		string s;
		cin >> s;
		if (!cin) break;
		for (auto &c : s) c = toupper(c);
		int flag = which_flag(s);
		if (choice == "ADD") {
			if (flag == KEYS) keys += string_to_key(s);
			else if (flag == JOBS) jobs += string_to_job(s);
			else if (flag == WEAPONS) weapons += string_to_weapon(s);
		} else if (choice == "DELETE") {
			if (flag == KEYS) keys -= string_to_key(s);
			else if (flag == JOBS) jobs -= string_to_job(s);
			else if (flag == WEAPONS) weapons -= string_to_weapon(s);
		} else if (choice == "QUERY") {
			bool found = false;
			if (flag == KEYS) found = (keys == string_to_key(s));
			else if (flag == JOBS) found = (jobs ==  string_to_job(s));
			else if (flag == WEAPONS) found = (weapons == string_to_weapon(s));
			if (found) cout << "TRUE\n";
			else cout << "FALSE\n";
		} else if (choice == "SELECT") {
			cin >> s;
			if (!cin) break;
			cout << weapon_to_string(weapons.select_best_weapon()) << endl;
		} else throw runtime_error("Invalid Input");
	}

	//YOU: Write a main loop that will allow the user to set, clear, and test to see if certain flags are set
	// within the bitfields declared above. You'll need to keep track of three:
	//1) keys, which will hold the values from key_colors::red through black.
	//2) jobs, which will hold the const ints for jobs, with special rules (you can only have one job)
	//3) weapons, which will allow the user to query what the best weapon he has is.

	//SYNTAX:
	//"ADD <flagname>" will add the flag to the appropriate bitfield. (Example: "ADD RED" or "ADD WEAP_ROCKET_LAUNCHER" or "ADD JOB_PSION") (JOB_ALL cannot be set by the user)
	//"DELETE <flagname>" removes the flag from the appropriate bitfield. (Example: "REMOVE ORANGE" will clear the orange flag from the keys bitfield.
	//"QUERY <flagname>" will cout "TRUE" if the flag is set in the appropriate bitfield, or "FALSE" otherwise. (Example: "ADD JOB_PSION", "QUERY JOB_PSION" will print "TRUE" to the screen.)
	//"SELECT BEST WEAPON will cout the name of the highest bit set (Example: If the bits for the axe and rocket launcher have been set, it will print to the screen "WEAP_ROCKET_LAUNCHER".)
	//On an invalid command (i.e. not one of the four possibilities above), throw a runtime_error with the string "Invalid Input", and let it kill the program
}
