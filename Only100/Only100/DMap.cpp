#include"DMap.h"
DMap::DMap() {
	num.resize(1281, vector<int>(721));	
}
void DMap::InitMap(int n) {
	switch (n) {
		case -1:
		{
			for (int i = 0; i <= 1280; i++) {
				for (int j = 0; j <= 720; j++) {
					num[i][j] = 0;
				}
			}
			for (int i = 800; i <= 1280; i++) {
				for (int j = 1; j <= 720; j++) {
					num[i][j] = 2;
				}
			}
			for (int i = 0; i <= 1280; i++) {
				for (int j = 700; j <= 720; j++) {
					num[i][j] = 1;
				}

			}
			break;
		}
			
		case 1: 
		{
			for (int i = 0; i <= 1280; i++) {
				for (int j = 0; j <= 720; j++) {
					num[i][j] = 0;
				}
			}
			for (int i = 418; i <= 450; i++) {
				for (int j = 562; j <= 563; j++) {
					num[i][j] = 1;
				}

			}
			for (int i = 555; i <= 620; i++) {
				for (int j = 484; j <= 485; j++) {
					num[i][j] = 1;
				}

			}
			for (int i = 710; i <= 774; i++) {
				for (int j = 404; j <= 405; j++) {
					num[i][j] = 1;
				}

			}
			for (int i = 865; i <= 1279; i++) {
				for (int j = 321; j <= 322; j++) {
					num[i][j] = 1;
				}

			}
			for (int i = 0; i <= 1280; i++) {
				for (int j = 660; j <= 661; j++) {
					num[i][j] = 1;
				}

			}
			for (int i = 210; i <= 270; i++) {
				for (int j = 600; j <= 659; j++) {
					num[i][j] = 21;
				}

			}
			for (int i = 962; i <= 1027; i++) {
				for (int j = 267; j <= 320; j++) {
					num[i][j] = 22;
				}

			}
			for (int i = 1114; i <= 1200; i++) {
				for (int j = 139; j <= 320; j++) {
					num[i][j] = 522;
				}

			}
			break;
		}
			
		case 2: 
		{
			for (int i = 0; i <= 1280; i++) {
				for (int j = 0; j <= 720; j++) {
					num[i][j] = 0;
				}
			}

			for (int i = 0; i <= 1280; i++) {
				for (int j = 648; j <= 720; j++) {
					num[i][j] = 1;
				}
			}


			for (int i = 1150; i <= 1279; i++) {
				for (int j = 200; j <= 317; j++) {
					num[i][j] = 523;
				}
			}

			for (int i = 1150; i <= 1279; i++) {
				for (int j = 450; j <= 647; j++) {
					num[i][j] = 522;
				}
			}

			for (int i = 0; i <= 223; i++) {
				for (int j = 345; j <= 347; j++) {
					num[i][j] = 1;
				}
			}
			for (int i = 50; i <= 100; i++) {
				for (int j = 250; j <= 344; j++) {
					num[i][j] = 100;
				}
			}
			for (int i = 130; i <= 200; i++) {
				for (int j = 250; j <= 344; j++) {
					num[i][j] = 21;
				}
			}

			for (int i = 292; i <= 388; i++) {
				for (int j = 253; j <= 255; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 292; i <= 388; i++) {
				for (int j = 443; j <= 445; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 133; i <= 229; i++) {
				for (int j = 540; j <= 542; j++) {
					num[i][j] = 1;
				}
			}





			for (int i = 508; i <= 604; i++) {
				for (int j = 188; j <= 190; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 660; i <= 691; i++) {
				for (int j = 165; j <= 167; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 759; i <= 790; i++) {
				for (int j = 218; j <= 220; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 850; i <= 946; i++) {
				for (int j = 178; j <= 179; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 1007; i <= 1069; i++) {
				for (int j = 134; j <= 135; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 453; i <= 1117; i++) {
				for (int j = 300; j <= 318; j++) {
					num[i][j] = 11;
				}
			}
			break;
		}
			
		case 3: 
		{
			for (int i = 0; i < 1280; i++) {
				for (int j = 0; j < 720; j++) {
					num[i][j] = 0;
				}
			}
			for (int i = 0; i < 1280; i++) {
				for (int j = 650; j <= 652; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 310; i <= 460; i++) {
				for (int j = 548; j <= 550; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 235; i <= 280; i++) {
				for (int j = 475; j <= 477; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 155; i <= 200; i++) {
				for (int j = 415; j <= 417; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 0; i <= 100; i++) {
				for (int j = 365; j <= 367; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 880; i <= 1012; i++) {
				for (int j = 545; j <= 547; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 1070; i <= 1148; i++) {
				for (int j = 490; j <= 492; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 945; i <= 1060; i++) {
				for (int j = 415; j <= 417; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 1130; i <= 1170; i++) {
				for (int j = 370; j <= 372; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 1000; i <= 1125; i++) {
				for (int j = 275; j <= 277; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 505; i <= 955; i++) {
				for (int j = 217; j <= 219; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 400; i <= 430; i++) {
				for (int j = 217; j <= 219; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 0; i <= 300; i++) {
				for (int j = 217; j <= 219; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 0; i <= 100; i++) {
				for (int j = 100; j <= 210; j++) {
					num[i][j] = 522;
				}
			}

			for (int i = 100; i <= 200; i++) {
				for (int j = 560; j <= 639; j++) {
					num[i][j] = 100;
				}
			}
			for (int i = 280; i <= 350; i++) {
				for (int j = 560; j <= 639; j++) {
					num[i][j] = 21;
				}
			}
			break;
		}
			
		case 4:
		{
			for (int i = 0; i <= 1280; i++) {
				for (int j = 0; j <= 720; j++) {
					num[i][j] = 0;
				}
			}

			for (int i = 0; i <= 260; i++) {
				for (int j = 195; j <= 197; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 0; i <= 1280; i++) {
				for (int j = 660; j <= 720; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 322; i <= 422; i++) {
				for (int j = 155; j <= 156; j++) {
					num[i][j] = 1;
				}
			}
			for (int i = 504; i <= 598; i++) {
				for (int j = 255; j <= 256; j++) {
					num[i][j] = 1;
				}
			}
			for (int i = 675; i <= 769; i++) {
				for (int j = 193; j <= 194; j++) {
					num[i][j] = 1;
				}
			}
			for (int i = 844; i <= 939; i++) {
				for (int j = 109; j <= 110; j++) {
					num[i][j] = 1;
				}
			}
			for (int i = 1080; i <= 1280; i++) {
				for (int j = 200; j <= 201; j++) {
					num[i][j] = 1;
				}
			}
			for (int i = 150; i <= 200; i++) {
				for (int j = 100; j <= 191; j++) {
					num[i][j] = 21;
				}
			}
			for (int i = 0; i <= 95; i++) {
				for (int j = 100; j <= 191; j++) {
					num[i][j] = 100;
				}
			}
			for (int i = 534; i <= 610; i++) {
				for (int j = 550; j <= 660; j++) {
					num[i][j] = 555;
				}
			}

			for (int i = 1213; i <= 1256; i++) {
				for (int j = 0; j <= 199; j++) {
					num[i][j] = 522;
				}
			}
			break;
		}
			
		case 5:
		{
			for (int i = 0; i <= 1280; i++) {
				for (int j = 0; j <= 720; j++) {
					num[i][j] = 0;
				}
			}

			for (int i = 0; i <= 120; i++) {
				for (int j = 250; j <= 301; j++) {
					num[i][j] = 522;
				}
			}

			for (int i = 0; i < 1280; i++) {
				for (int j = 650; j <= 720; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 1035; i <= 1130; i++) {
				for (int j = 565; j <= 567; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 910; i <= 1005; i++) {
				for (int j = 490; j <= 492; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 797; i <= 893; i++) {
				for (int j = 358; j <= 360; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 553; i <= 648; i++) {
				for (int j = 357; j <= 358; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 353; i <= 456; i++) {
				for (int j = 358; j <= 359; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 230; i <= 330; i++) {
				for (int j = 375; j <= 376; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 230; i <= 330; i++) {
				for (int j = 595; j <= 596; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 250; i <= 310; i++) {
				for (int j = 500; j <= 590; j++) {
					num[i][j] = 555;
				}
			}

			for (int i = 0; i <= 219; i++) {
				for (int j = 302; j <= 303; j++) {
					num[i][j] = 1;
				}
			}

			for (int i = 845; i <= 885; i++) {
				for (int j = 637; j <= 652; j++) {
					num[i][j] = 11;
				}
			}

			for (int i = 757; i <= 795; i++) {
				for (int j = 637; j <= 652; j++) {
					num[i][j] = 11;
				}
			}

			for (int i = 572; i <= 603; i++) {
				for (int j = 600; j <= 650; j++) {
					num[i][j] = 11;
				}
			}

			

			for (int i = 755; i <= 781; i++) {
				for (int j = 349; j <= 375; j++) {
					num[i][j] = 11;
				}
			}

			for (int i = 672; i <= 702; i++) {
				for (int j = 349; j <= 375; j++) {
					num[i][j] = 11;
				}
			}

			for (int i = 714; i <= 740; i++) {
				for (int j = 327; j <= 353; j++) {
					num[i][j] = 11;
				}
			}
			for (int i = 1000; i <= 1110; i++) {
				for (int j = 590; j <= 640; j++) {
					num[i][j] = 100;
				}
			}
			for (int i = 1150; i <= 1280; i++) {
				for (int j = 590; j <= 640; j++) {
					num[i][j] = 21;
				}
			}
			for (int i = 910; i <= 980; i++) {
				for (int j = 590; j <= 640; j++) {
					num[i][j] = 22;
				}
			}
			break;
		}

		case 6:
		{
			for (int i = 0; i <= 1280; i++) {
				for (int j = 0; j <= 720; j++) {
					num[i][j] = 0;
				}
			}
			for (int i = 0; i <= 1280; i++) {
				for (int j = 629; j <= 720; j++) {
					num[i][j] = 1;
				}

			}
			for (int i = 277; i <= 356; i++) {
				for (int j = 550; j <= 629; j++) {
					num[i][j] = 21;
				}

			}
			for (int i = 70; i <= 165; i++) {
				for (int j = 550; j <= 629; j++) {
					num[i][j] = 100;
				}

			}
			for (int i = 1180; i <= 1280; i++) {
				for (int j = 520; j <= 630; j++) {
					num[i][j] = 522;
				}

			}
			break;
		}
			
		default:
			break;
	}
}
int DMap::get_num(int x, int y) {
	return num[x][y];
}
