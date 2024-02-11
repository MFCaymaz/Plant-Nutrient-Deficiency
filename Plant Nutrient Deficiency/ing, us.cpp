#include <stdio.h>


const char *symptoms[] = {"genc yapraklarda sekil bozuklugu", "yapraklar daralmis", "yapraklar dalgali-kivrik", "nekroz-kahverengilesme", "bodur buyume","damarlar arasi sari","yaprak gri lekelenme", "genel sararma","yapraklar koyu yesil ","sararma genc yapraklarda basladi","yaprak gelisimi az","yasli yapraklarda sararma","erken olgunlasma"};
const char *diagnoses[] = {"azot eksikligi,", "fosfor eksikligi,", "potasyum eksikligi,", "magnezyum eksikligi,", "kalsiyum eksikligi,", "bakir eksikligi,", "cinko eksikligi,", "mangan eksikligi,", "demir eksikligi,"};


const char *rules[][13] = {
  {"bodur buyume","sararma genc yapraklarda basladi","yasli yapraklarda sararma","damarlar arasi sari","genel sararma","erken olgunlasma"},          // nitrogen deficiency
  {"yaprak gelisimi az", "yapraklar koyu yesil "},                                                                                                  // phosphorus deficiency
  {"nekroz-kahverengilesme", "bodur buyume", "yapraklar dalgali-kivrik","yasli yapraklarda sararma"},                                              //  potassium deficiency
  {"nekroz-kahverengilesme", "nekroz-kahverengilesme"},                                                                                           // magnesium deficiency
  {"genc yapraklarda sekil bozuklugu","sararma genc yapraklarda basladi","damarlar arasi sari" },                                                //	calcium deficiency
  {"genc yapraklarda sekil bozuklugu", "yapraklar daralmis", "yapraklar dalgali-kivrik","nekroz-kahverengilesme" },                             // copper deficiency
  {"bodur buyume","damarlar arasi sari"},                                                                                                      // zinc deficiency
  {"bodur buyume", "yaprak gri lekelenme"},                                                                                                   // manganese deficiency
  {"damarlar arasi sari","sararma genc yapraklarda basladi", "genel sararma"},                                                               // iron deficiency

};


const int numSymptoms = sizeof(symptoms) / sizeof(symptoms[0]);
const int numDiagnoses = sizeof(diagnoses) / sizeof(diagnoses[0]);

int main() {
  
  int hasSymptoms[numSymptoms];
  for (int i = 0; i < numSymptoms; i++) {
    
    printf("Does the plant have %s? (1 for yes, 0 for no) ", symptoms[i]);
    scanf("%d", &hasSymptoms[i]);
  }

  
  int isPossible[numDiagnoses];
  for (int i = 0; i < numDiagnoses; i++) {
    
    isPossible[i] = 1;

    
    for (int j = 0; j < numSymptoms; j++) {
      
      
      if (rules[i][j] && !hasSymptoms[j]) {
        isPossible[i] = 0;
        break;
      }
    }
  }

  
  printf("Possible diagnoses: ");
  for (int i = 0; i < numDiagnoses; i++) {
    if (isPossible[i]) {
      printf("%s ", diagnoses[i]);
    }
  }
  printf("\n");

  return 0;
}
