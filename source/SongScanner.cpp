#include "SongScanner.h"

//alias to make code shorter (and easier to read)
namespace fs = std::experimental::filesystem;

//recursive scan inside folders to find songs 
void checkFolder(fs::path p, std::vector<SongEntry>&list) {
	for (const fs::directory_entry entry : fs::directory_iterator(p)) {
		//if there's a sub-directory, repeat the scan inside that sub-directory
		if (fs::is_directory(entry)) {
			checkFolder(entry.path(), list);
		}
		//if it's not a directory, check for info.txt
		std::string file = p.generic_string() + std::string("/info.ini");
		fs::path filePath(file);
		if (fs::exists(filePath)) {
			std::ifstream fileData(file);

			CSimpleIniA ini;
			ini.LoadFile(file.c_str());

			std::string s1;
			std::string s2;
			std::string a1;
			std::string a2;
			std::string charter;
			std::string mixer;
			int dTrack;
			int dTap;
			int dCrossfade;
			int dScratch;
			
			s1 = ini.GetValue("song", "name", "NULL");
			s2 = ini.GetValue("song", "name2", "NULL");
			a1 = ini.GetValue("song", "artist", "NULL");
			a2 = ini.GetValue("song", "artist2", "NULL");
			charter = ini.GetValue("song", "charter", "NULL");
			mixer = ini.GetValue("song", "dj", "NULL");

			dTrack = ini.GetLongValue("song", "track_complexity", 0);
			dTap = ini.GetLongValue("song", "tap_complexity", 0);
			dCrossfade = ini.GetLongValue("song", "crossfade_complexity", 0);
			dScratch = ini.GetLongValue("song", "scratch_complexity", 0);

			dTrack = (dTrack < 100 ? dTrack : 100);//min(dTrack, 100);
			dTrack = (dTrack > 0 ? dTrack : 0);//max(dTrack, 0);

			dTap = (dTap < 100 ? dTap : 100);//min(dTap, 100);
			dTap = (dTap > 0 ? dTap : 0);//max(dTap, 0);

			dCrossfade = (dCrossfade < 100 ? dCrossfade : 100);//min(dCrossfade, 100);
			dCrossfade = (dCrossfade > 0 ? dCrossfade: 0);//max(dCrossfade, 0);

			dScratch = (dScratch < 100 ? dScratch: 100);//min(dScratch, 100);
			dScratch = (dScratch > 0 ? dScratch : 0);//max(dScratch, 0);

			if (s2 == std::string("NULL")) {
				s2.clear();
			}

			if (a2 == std::string("NULL")) {
				a2.clear();
			}

			SongEntry t = {
				p.generic_string(),
				s1, s2,
				a1, a2,
				charter, mixer,
				dTrack, dTap,
				dCrossfade, dScratch
			};

			list.push_back(t);
			std::cout << "found " << file << std::endl;
			break;
		}
	}
}


void SongScanner::load(const std::string& rootPath,std::vector<SongEntry>& list){
	fs::path root(rootPath);
	if (fs::is_directory(root)) {
		//the root is a directory, so start scanning
		checkFolder(root, list);
	}
	else {
		std::cerr << "SongScanner error: Root path is not a folder" << std::endl;
	}
}
