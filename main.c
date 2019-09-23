#include "includes/ft_printf.h"
#include <stdio.h>

int main()
{

// d & i & D tests
/*
	printf("\n*****--- d & i & D ft_printf tests--- *****\n");

    ft_printf("test d m %d\n", 42);
    printf("test d t %d\n", 42);

    ft_printf("test i m %d\n", 42);
    printf("test i t %d\n", 42);

	ft_printf("test d m Kashim a %d histoires à raconter\n", 1001);
	printf("test d t Kashim a %d histoires à raconter\n", 1001);

	ft_printf("test d m Il fait au moins %d\n", -8000);
    printf("test d t Il fait au moins %d\n", -8000);

	ft_printf("test d m %d\n", -0);
    printf("test d t %d\n", -0);

	ft_printf("test d m %d\n", 0);
	printf("test d t %d\n", 0);

	ft_printf("test d m %d\n", INT_MAX);
	printf("test d t %d\n", INT_MAX);

	ft_printf("test d m %d\n", INT_MIN);
	printf("test d t %d\n", INT_MIN);

	ft_printf("test d m %d\n", INT_MIN - 1);
	printf("test d t %d\n", INT_MIN - 1);

	ft_printf("test d m %d\n", INT_MAX + 1);
	printf("test d t %d\n", INT_MAX + 1);

	ft_printf("test d m %%d 0000042 == |%d|\n", 0000042);
	printf("test d t %%d 0000042 == |%d|\n", 0000042);

	ft_printf("test d m %%d \t == |%d|\n", '\t');
	printf("test d t %%d \t == |%d|\n", '\t');

	ft_printf("test d m %%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');
	printf("test d t %%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');
*/

// c & C tests - seems all pass
/*
	printf("\n*****--- c & C ft_printf tests ---*****\n");

    ft_printf("test c m %c\n", 'a');
    printf("test c t %c\n", 'a');

    ft_printf("test C m %C\n", 'a');
    printf("test C t %C\n", 'a');

	ft_printf("test c m %c\n", 42);
    printf("test c t %c\n", 42);

    ft_printf("test c m Kashim a %c histoires à raconter\n", 1001);
	printf("test c t Kashim a %c histoires à raconter\n", 1001);

	ft_printf("test c m Il fait au moins %c\n", -8000);
	printf("test c t Il fait au moins %c\n", -8000);

    ft_printf("test c m -0 %c\n", -0);
	printf("test c t -0 %c\n", -0);

	ft_printf("test c m 0 %c\n", 0);
	printf("test c t 0 %c\n", 0);

	ft_printf("test c m %c\n", INT_MAX);
	printf("test c t %c\n", INT_MAX);

	ft_printf("test c m %c\n", 'c');
	printf("test c t %c\n", 'c');

	ft_printf("test c m %c\n", '\n');
	printf("test c t %c\n", '\n');

	ft_printf("test c m %c\n", 'l');
	printf("test c t %c\n", 'l');

	ft_printf("test c m %c\n", 'y');
	printf("test c t %c\n", 'y');

	ft_printf("test c m %c\n", ' ');
	printf("test c t %c\n", ' ');

    ft_printf("test c m %c\n", 'e');
	printf("test c t %c\n", 'e');

	ft_printf("test c m %c\n", 's');
	printf("test c t %c\n", 's');

	ft_printf("test c m %c\n", 't');
	printf("test c t %c\n", 't');

	ft_printf("test c m %c\n", 'f');
	printf("test c t %c\n", 'f');

	ft_printf("test c m %c\n", 'a');
	printf("test c t %c\n", 'a');

	ft_printf("test c m %c\n", 'n');
	printf("test c t %c\n", 'n');

	ft_printf("test c m %c\n", 'i');
	printf("test c t %c\n", 'i');

	ft_printf("test c m %c\n", 'q');
	printf("test c t %c\n", 'q');

	ft_printf("test c m %c\n", 'u');
	printf("test c t %c\n", 'u');

	ft_printf("test c m %c\n", '!');
	printf("test c t %c\n", '!');

	ft_printf("test c m %c\n", '\r');
	printf("test c t %c\n", '\r');

	ft_printf("test c m %c\n", '\t');
	printf("test c t %c\n", '\t');
*/
/*
// s tests

	printf("\n*****--- s ft_printf tests ---*****\n");

    ft_printf("test s m %s\n", "hello there");
    printf("test s t %s\n", "hello there");

	ft_printf("test s m %s\n", "pouet");
	printf("test s t %s\n", "pouet");

	ft_printf("test s m  pouet %s !!\n", "camembert");
	printf("test s t  pouet %s !!\n", "camembert");

	ft_printf("test s m %s !\n", "Ceci n'est pas un \0 exercice !");
	printf("test s t %s !\n", "Ceci n'est pas un \0 exercice !");

	ft_printf("test s m %s!\n", "Ceci n'est toujours pas un exercice !");
	printf("test s t %s!\n", "Ceci n'est toujours pas un exercice !");

	//char		*str = NULL;
	//ft_printf("test s m %s!\n", str);
	//printf("test s t %s!\n", str);

	//ft_printf("test s m %s\n", "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*");
	//printf("test s t %s\n", "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*");

// u & U tests

	printf("\n*****--- u & U ft_printf tests ---*****\n");

    ft_printf("test u %u\n", 24);
    printf("test u %u\n", 24);

    ft_printf("test u %u\n", -24);
    printf("test u %u\n", -24);

    ft_printf("test U %U\n", 24);
    printf("test U %U\n", 24);

	ft_printf("%u\n", 42);
	printf("%u\n", 42);

	ft_printf("Kashim a %u histoires à raconter\n", 1001);
	printf("Kashim a %u histoires à raconter\n", 1001);

	ft_printf("Il fait au moins %u\n", -8000);
	printf("Il fait au moins %u\n", -8000);

	ft_printf("%u\n", -0);
	printf("%u\n", -0);

	ft_printf("%u\n", 0);
	printf("%u\n", 0);

	ft_printf("%u\n", INT_MAX);
	printf("%u\n", INT_MAX);

	ft_printf("%u\n", INT_MIN);
	printf("%u\n", INT_MIN);

	ft_printf("%u\n", INT_MIN - 1);
	printf("%u\n", INT_MIN - 1);

	ft_printf("%u\n", INT_MAX + 1);
	printf("%u\n", INT_MAX + 1);

	ft_printf("m %%u 0000042 == |%u|\n", 0000042);
	printf("t %%u 0000042 == |%u|\n", 0000042);

	ft_printf("m %%u \t == |%u|\n", '\t');
	printf("t %%u \t == |%u|\n", '\t');

	ft_printf("m %%u Lydie == |%u|\n", 'L'+'y'+'d'+'i'+'e');
	printf("t %%u Lydie == |%u|\n", 'L'+'y'+'d'+'i'+'e');

// o & O tests


	printf("\n*****--- o & O ft_printf tests ---*****\n");

    ft_printf("test o %o\n", 24);
    printf("test o %o\n", 24);

    ft_printf("test O %O\n", 24);
    printf("test O %O\n", 24);

	ft_printf("%o\n", 42);
	printf("%o\n", 42);

	ft_printf("Kashim a %o histoires à raconter\n", 1001);
	printf("Kashim a %o histoires à raconter\n", 1001);

	ft_printf("Il fait au moins %o\n", -8000);
	printf("Il fait au moins %o\n", -8000);

	ft_printf("%o\n", -0);
	printf("%o\n", -0);

	ft_printf("%o\n", 0);
	printf("%o\n", 0);

	ft_printf("%o\n", INT_MAX);
	printf("%o\n", INT_MAX);

	ft_printf("%o\n", INT_MIN);
	printf("%o\n", INT_MIN);

	ft_printf("%o\n", INT_MIN - 1);
	printf("%o\n", INT_MIN - 1);

	ft_printf("%o\n", INT_MAX + 1);
	printf("%o\n", INT_MAX + 1);

	ft_printf("m %%o 0000042 == |%o|\n", 0000042);
	printf("t %%o 0000042 == |%o|\n", 0000042);

	ft_printf("m %%o \t == |%o|\n", '\t');
	printf("t %%o \t == |%o|\n", '\t');

	ft_printf("m %%o Lydie == |%o|\n", 'L'+'y'+'d'+'i'+'e');
	printf("t %%o Lydie == |%o|\n", 'L'+'y'+'d'+'i'+'e');

// x & X tests

	printf("\n*****--- x & X ft_printf tests ---*****\n");

    ft_printf("test x m %x\n", 24);
    printf("test x t %x\n", 24);

    ft_printf("test X m %X\n", 24);
    printf("test X t %X\n", 24);

	ft_printf("%x\n", 42);
	printf("%x\n", 42);

	ft_printf("Kashim a %x histoires à raconter\n", 1001);
	printf("Kashim a %x histoires à raconter\n", 1001);

	ft_printf("Il fait au moins %x\n", -8000);
	printf("Il fait au moins %x\n", -8000);

	ft_printf("%x\n", -0);
	printf("%x\n", -0);

	ft_printf("%x\n", 0);
	printf("%x\n", 0);

	ft_printf("%x\n", INT_MAX);
	printf("%x\n", INT_MAX);

	ft_printf("%x\n", INT_MIN);
	printf("%x\n", INT_MIN);

	ft_printf("%x\n", INT_MIN - 1);
	printf("%x\n", INT_MIN - 1);

	ft_printf("%x\n", INT_MAX + 1);
	printf("%x\n", INT_MAX + 1);

	ft_printf("m %%x 0000042 == |%x|\n", 0000042);
	printf("t %%x 0000042 == |%x|\n", 0000042);

	ft_printf("m %%x \t == |%x|\n", '\t');
	printf("t %%x \t == |%x|\n", '\t');

	ft_printf("m %%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');
	printf("t %%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');

	ft_printf("test X m %X\n", 24);
    printf("test X t %X\n", 24);

    ft_printf("test X m %X\n", 24);
    printf("test X t %X\n", 24);

	ft_printf("%X\n", 42);
	printf("%X\n", 42);

	ft_printf("Kashim a %X histoires à raconter\n", 1001);
	printf("Kashim a %X histoires à raconter\n", 1001);

	ft_printf("Il fait au moins %X\n", -8000);
	printf("Il fait au moins %X\n", -8000);

	ft_printf("%X\n", -0);
	printf("%X\n", -0);

	ft_printf("%X\n", 0);
	printf("%X\n", 0);

	ft_printf("%X\n", INT_MAX);
	printf("%X\n", INT_MAX);

	ft_printf("%X\n", INT_MIN);
	printf("%X\n", INT_MIN);

	ft_printf("%X\n", INT_MIN - 1);
	printf("%X\n", INT_MIN - 1);

	ft_printf("%X\n", INT_MAX + 1);
	printf("%X\n", INT_MAX + 1);

	ft_printf("m %%x 0000042 == |%X|\n", 0000042);
	printf("t %%x 0000042 == |%X|\n", 0000042);

	ft_printf("m %%x \t == |%X|\n", '\t');
	printf("t %%x \t == |%X|\n", '\t');

	ft_printf("m %%x Lydie == |%X|\n", 'L'+'y'+'d'+'i'+'e');
	printf("t %%x Lydie == |%X|\n", 'L'+'y'+'d'+'i'+'e');

// Plus test

	printf("\n*****--- + ft_printf tests ---*****\n");

	ft_printf("%%+d 42 == %+d\n", INT_MAX);
	printf("%%+d 42 == %+d\n", INT_MAX);

	ft_printf("%%+i -42 == %+i\n", -42);
	printf("%%+i -42 == %+i\n", -42);

	ft_printf("m %0+04d\n", 42);
	printf("t %0+04d\n", 42);

// Zero test

	printf("\n*****--- 0 ft_printf tests ---*****\n");

	ft_printf("%%04i 42 == |%04i|\n", 42);
	printf("%%04i 42 == |%04i|\n", 42);

	ft_printf("%%05i 42 == |%05i|\n", 42);
	printf("%%05i 42 == |%05i|\n", 42);

	ft_printf("%%0i 42 == |%0i|\n", 42);
	printf("%%0i 42 == |%0i|\n", 42);

	ft_printf("%%0d 0000042 == |%0d|\n", 0000042);
	printf("%%0d 0000042 == |%0d|\n", 0000042);


// Space test

	printf("\n*****--- ' ' ft_printf tests ---*****\n");

	ft_printf("%%      i 42 == |%      i|\n", 42);
	printf("%%      i 42 == |%      i|\n", 42);

	ft_printf("%% i -42 == |% i|\n", -42);
	printf("%% i -42 == |% i|\n", -42);

	ft_printf("|% 4i|\n", 42);
	printf("|% 4i|\n", 42);

// Alt test

	printf("\n*****--- alt mode ft_printf tests ---*****\n");

	ft_printf("%%X 42 ==  %X\n", 42);
	printf("%%X 42 ==  %X\n", 42);

	ft_printf("%%o 0 ==  %o\n", 0);
	printf("%%o 0 ==  %o\n", 0);

	ft_printf("%%#o INT_MAX ==  %#o\n", INT_MAX);
	printf("%%#o INT_MAX ==  %#o\n", INT_MAX);

	ft_printf("%%o INT_MAX ==  %o\n", INT_MAX);
	printf("%%o INT_MAX ==  %o\n", INT_MAX);

	ft_printf("%%#o INT_MIN ==  %#o\n", INT_MIN);
	printf("%%#o INT_MIN ==  %#o\n", INT_MIN);

	ft_printf("%%o INT_MIN ==  %o\n", INT_MIN);
	printf("%%o INT_MIN ==  %o\n", INT_MIN);

	ft_printf("%%#X INT_MIN ==  %#X\n", INT_MIN);
	printf("%%#X INT_MIN ==  %#X\n", INT_MIN);

	ft_printf("%%X INT_MIN ==  %X\n", INT_MIN);
	printf("%%X INT_MIN ==  %X\n", INT_MIN);

	ft_printf("%%X INT_MAX ==  %X\n", INT_MAX);
	printf("%%X INT_MAX ==  %X\n", INT_MAX);

// Precision test

	printf("\n*****--- precision ft_printf tests ---*****\n");

	ft_printf("ft%%04.5i 42 == |%04.5i|\n", 42);
	printf("ft%%04.5i 42 == |%04.5i|\n", 42);

	ft_printf("ft%%04.3i 42 == |%04.3i|\n", 42);
	printf("ft%%04.3i 42 == |%04.3i|\n", 42);

	ft_printf("ft%%04.2i 42 == |%04.2i|\n", 42);
	printf("ft%%04.2i 42 == |%04.2i|\n", 42);

*/
// end of the line ----------------------------------------------------------------

/*
// p tests

	printf("\n*****--- p & P ft_printf tests ---*****\n");

    ft_printf("test p m %p\n", 24);
    printf("test p t %p\n", 24);
// f tests

	printf("\n*****--- f ft_printf tests ---*****\n");
    ft_printf("test f m %f\n", 24.0024);
    printf("test f t %f\n", 24.0024);

	ft_printf("%f\n", (double)42);
	printf("%f\n", (double)42);

	ft_printf("Kashim a %f histoires à raconter\n", (double)1001);
	printf("Kashim a %f histoires à raconter\n", (double)1001);

	ft_printf("Il fait au moins %f\n", (double)-8000);
	printf("Il fait au moins %f\n", (double)-8000);

	ft_printf("%f\n", (double)-0);
	printf("%f\n", (double)-0);

	ft_printf("%f\n", (double)0);
	printf("%f\n", (double)0);

	ft_printf("%f\n", (double)INT_MAX);
	printf("%f\n", (double)INT_MAX);

	ft_printf("%f\n", (double)INT_MIN);
	printf("%f\n", (double)INT_MIN);

	ft_printf("%f\n", (double)INT_MIN - 1);
	printf("%f\n", (double)INT_MIN - 1);

	ft_printf("%f\n", (double)INT_MAX + 1);
	printf("%f\n", (double)INT_MAX + 1);

	ft_printf("%%f 0000042 == |%f|\n", (double)0000042);
	printf("%%f 0000042 == |%f|\n", (double)0000042);

	ft_printf("%%f \t == |%f|\n", (double)'\t');
	printf("%%f \t == |%f|\n", (double)'\t');

	ft_printf("%%f Lydie == |%f|\n", (double)'L'+'y'+'d'+'i'+'e');
	printf("%%f Lydie == |%f|\n", (double)'L'+'y'+'d'+'i'+'e');

	ft_printf("%%f 42.42 == |%f|\n", 42.42);
	printf("%%f 42.42 == |%f|\n", 42.42);
*/

// File Checker Fails
/*
	printf("\n*****--- Re Broken Tests ---*****\n");

	printf("\n*****--- x Test --------------------------------------\n");

	ft_printf("m %10x\n", 42);
	printf("t %10x\n", 42);

	ft_printf("m %-10x\n", 42);
	printf("t %-10x\n", 42);

	ft_printf("%%#X INT_MAX ==  %#X\n", INT_MAX);
	printf("%%#X INT_MAX ==  %#X\n", INT_MAX);

	ft_printf("%%#X 42 ==  %#X\n", 42);
	printf("%%#X 42 ==  %#X\n", 42);

	ft_printf("m %#X\n", 42);
	printf("t %#X\n", 42);

	ft_printf("m %#8x\n", 42);
	printf("t %#8x\n", 42);

	ft_printf("m %#08x\n", 42); //alt mode affects zeroes?
	printf("t %#08x\n", 42);

	printf("\n * group ----------\n");

	ft_printf("m %#x\n", 0);
	printf("t %#x\n", 0);

	ft_printf("m @moulitest: %#.x %#.0x\n", 0, 0);
	printf("t @moulitest: %#.x %#.0x\n", 0, 0);

	ft_printf("m @moulitest: %.x %.0x\n", 0, 0);
	printf("t @moulitest: %.x %.0x\n", 0, 0);

	ft_printf("m @moulitest: %5.x %5.0x\n", 0, 0);
	printf("t @moulitest: %5.x %5.0x\n", 0, 0);

	printf("\n * end of group ----------\n");

	printf("\n*****--- s Test --------------------------------------\n");

	ft_printf("m %10s is a string\n", "this");
	printf("t %10s is a string\n", "this");

	ft_printf("m %10s is a string\n", "");
	printf("t %10s is a string\n", "");

	ft_printf("m %-10s is a string\n", "this");
	printf("t %-10s is a string\n", "this");

	ft_printf("m %-10s is a string\n", "");
	printf("t %-10s is a string\n", "");
*/
/*
	printf("\n*****--- o Test --------------------------------------\n");

	ft_printf("m @moulitest: %.o %.0o\n", 0, 0);
	printf("t @moulitest: %.o %.0o\n", 0, 0);

	ft_printf("m @moulitest: %5.o %5.0o\n", 0, 0);
	printf("t @moulitest: %5.o %5.0o\n", 0, 0);

	ft_printf("m @moulitest: %#.o %#.0o\n", 0, 0);
	printf("t @moulitest: %#.o %#.0o\n", 0, 0);

	ft_printf("%%#o 0 ==  %#o\n", 0);
	printf("%%#o 0 ==  %#o\n", 0);

	ft_printf("m %#6o\n", 2500);
	printf("t %#6o\n", 2500);

	ft_printf("%%+i 42 == %+i\n", 42);
	printf("%%+i 42 == %+i\n", 42);
*/
/*
	printf("\n*****--- d Test --------------------------------------\n");

	ft_printf("m %05d\n", -42);
	printf("t %05d\n", -42);

	ft_printf("m %0+5d\n", -42);
	printf("t %0+5d\n", -42);

	ft_printf("m % 10.5d\n", 4242);
	printf("t % 10.5d\n", 4242);

	ft_printf("m %+10.5d\n", 4242);
	printf("t %+10.5d\n", 4242);

	ft_printf("m %-+10.5d\n", 4242);
	printf("t %-+10.5d\n", 4242);

	ft_printf("m @moulitest: %.d %.0d\n", 0, 0);
	printf("t @moulitest: %.d %.0d\n", 0, 0);

	ft_printf("m @moulitest: %5.d %5.0d\n", 0, 0);
	printf("t @moulitest: %5.d %5.0d\n", 0, 0);


	printf("\n*****--- File Checker Failed Tests ---*****\n");
*/
/*
	printf("\n*****--- % Test --------------------------------------\n");
	ft_printf(""); // fixed?
	printf("");

	ft_printf("m %%\n");
	printf("t %%\n");

	ft_printf("m %5%\n");
	printf("t %5%\n");

	ft_printf("m %-5%\n");
	printf("t %-5%\n");

	ft_printf("m %.0%\n");
	printf("t %.0%\n");
*/
/*
	printf("\n*****--- x Test --------------------------------------\n");

	ft_printf("m %lx\n", 4294967296);
	printf("t %lx\n", 4294967296);

	ft_printf("m %-15x\n", 542);
	printf("t %-15x\n", 542);
*/
/*
	printf("\n*****--- s Test --------------------------------------\n");

	ft_printf("m %s\n", "abc");
	printf("t %s\n", "abc");

	ft_printf("m %s\n", "this is a string");
	printf("t %s\n", "this is a string");

	ft_printf("m this is a %s\n", "string");
	printf("t this is a %s\n", "string");

	ft_printf("m %.2s is a string\n", "this");
	printf("t %.2s is a string\n", "this");

	ft_printf("m %5.2s is a string\n", "this");
	printf("t %5.2s is a string\n", "this");

	ft_printf("m %-.2s is a string\n", "this");
	printf("t %-.2s is a string\n", "this");

	ft_printf("m %-5.2s is a string\n", "this");
	printf("t %-5.2s is a string\n", "this");

	ft_printf("m %s %s\n", "this", "is");
	printf("t %s %s\n", "this", "is");

	ft_printf("m %s %s %s\n", "this", "is", "a");
	printf("t %s %s %s\n", "this", "is", "a");

	ft_printf("m %s %s %s %s\n", "this", "is", "a", "multi");
	printf("t %s %s %s %s\n", "this", "is", "a", "multi");

	ft_printf("m %s%s%s%s%s\n", "this", "is", "a", "multi", "string");
	printf("t %s%s%s%s%s\n", "this", "is", "a", "multi", "string");

	ft_printf("m @moulitest: %s\n", NULL); //workaround fixed?
	printf("t @moulitest: %s\n", NULL);
*/
/*
	printf("\n*****--- c Test --------------------------------------\n");

	ft_printf("m %-5c\n", 42);
	printf("t %-5c\n", 42);

	ft_printf("m @moulitest: %c\n", 0);
	printf("t @moulitest: %c\n", 0);

	ft_printf("m %2c\n", 0);
	printf("t %2c\n", 0);

	ft_printf("m null %c and text\n", 0);
	printf("t null %c and text\n", 0);
*/
/*
	printf("\n*****--- o Test --------------------------------------\n");

	ft_printf("m %-5o\n", 2500);
	printf("t %-5o\n", 2500);

	ft_printf("m %-#6o\n", 2500);
	printf("t %-#6o\n", 2500);

	ft_printf("m %-5.10o\n", 2500);
	printf("t %-5.10o\n", 2500);

	ft_printf("m %-10.5o\n", 2500);
	printf("t %-10.5o\n", 2500);
*/
/*
	printf("\n*****--- d Test --------------------------------------\n");

	ft_printf("m %-5d\n", 42); // don't want 00 after numers if format = '-' no zeroes
	printf("t %-5d\n", 42);

	ft_printf("m %-5d\n", -42);
	printf("t %-5d\n", -42);

	ft_printf("m %ld\n", 2147483648);
	printf("t %ld\n", 2147483648);

	ft_printf("m %ld\n", -2147483649);
	printf("t %ld\n", -2147483649);

	ft_printf("m %4.15d\n", 42);
	printf("t %4.15d\n", 42);

	ft_printf("m %10.5d\n", 4242);
	printf("t %10.5d\n", 4242);

	ft_printf("m %-10.5d\n", 4242);
	printf("t %-10.5d\n", 4242);

	ft_printf("m %03.2d\n", -1);
	printf("t %03.2d\n", -1);

	ft_printf("m @moulitest: %.10d\n", -42);
	printf("t @moulitest: %.10d\n", -42);
	*/
/*
	printf("\n*****--- u Test --------------------------------------\n");

	ft_printf("m @moulitest: %.5u\n", 42);
	printf("t @moulitest: %.5u\n", 42);

	ft_printf("m %lu\n", 4294967296);
	printf("t %lu\n", 4294967296);
*/
/*

	printf("\n*****--- Undefined Failed Tests ---*****\n");

	ft_printf("m %%\n", "test");
	printf("t %%\n", "test"); // undefined

	ft_printf("m %   %\n", "test");
	printf("t %   %\n", "test"); // undefined

	ft_printf("%x\n", test);
	printf("%x\n", test);

	ft_printf("m %llX\n", 4294967296);
	printf("t %llX\n", 4294967296); // undefined

	ft_printf("m %hx\n", 4294967296);
	printf("t %hx\n", 4294967296); // undefined

	ft_printf("m %hhX\n", 4294967296);
	printf("t %hhX\n", 4294967296); // undefined

	ft_printf("m %llx\n", 9223372036854775807);
	printf("t %llx\n", 9223372036854775807); // undefined

	ft_printf("m %llx\n", 9223372036854775808); // undefined
	printf("t %llx\n", 9223372036854775808); // undefined

	ft_printf("m %#llx\n", 9223372036854775807);
	printf("t %#llx\n", 9223372036854775807); // undefined

	ft_printf("m %#-08x\n", 42);
	printf("t %#-08x\n", 42); // undefined

	ft_printf("m %.2c\n", NULL);
	printf("t %.2c\n", NULL); // undefined

	ft_printf("m %s %s\n", NULL, string);
	printf("t %s %s\n", NULL, string);

	ft_printf("m % c\n", 0);
	printf("t % c\n", 0); // undefined

	ft_printf("m %-05o\n", 2500);
	printf("t %-05o\n", 2500); // undefined

	ft_printf("m % +d\n", 42);
	printf("t % +d\n", 42); // undefined

	ft_printf("m %+ d\n", 42);
	printf("t %+ d\n", 42); // undefined

	ft_printf("m %  +d\n", 42);
	printf("t %  +d\n", 42); // undefined

	ft_printf("m %+  d\n", 42);
	printf("t %+  d\n", 42); // undefined

	ft_printf("m % ++d\n", 42);
	printf("t % ++d\n", 42); // undefined

	ft_printf("m %++ d\n", 42);
	printf("t %++ d\n", 42); // undefined

	ft_printf("m %-05d\n", 42);
	printf("t %-05d\n", 42); // undefined

	ft_printf("m %-05d\n", -42);
	printf("t %-05d\n", -42); // undefined

	ft_printf("m %hhd\n", 128);
	printf("t %hhd\n", 128); // undefined

	ft_printf("m %hhd\n", -129);
	printf("t %hhd\n", -129); // undefined

	ft_printf("m %lld\n", 9223372036854775807);
	printf("t %lld\n", 9223372036854775807); // undefined

	ft_printf("m %lld\n", -9223372036854775808); // undefined
	printf("t %lld\n", -9223372036854775808); // undefined

	ft_printf("m %-15u\n", 4294967295);
	printf("t %-15u\n", 4294967295); // undefined

	ft_printf("m % u\n", 4294967295);
	printf("t % u\n", 4294967295); // undefined

	ft_printf("m %+u\n", 4294967295);
	printf("t %+u\n", 4294967295); // undefined

	ft_printf("m %lu\n", -42);
	printf("t %lu\n", -42); // undefined

	ft_printf("m %llu\n", 4999999999);
	printf("t %llu\n", 4999999999); // undefined
*/
/*
	printf("\n*****--- Undefined Part 2 Failed Tests ---*****\n");

	ft_printf("m %\n");
	printf("t %\n");

	ft_printf("m % \n");
	printf("t % \n");

	ft_printf("m % h\n");
	printf("t % h\n");

	ft_printf("m %Z\n");
	printf("t %Z\n");

	ft_printf("m % hZ\n");
	printf("t % hZ\n");

	ft_printf("m %05%\n");
	printf("t %05%\n");

	ft_printf("m %-05%\n");
	printf("t %-05%\n");

	ft_printf("m % hZ%\n");
	printf("t % hZ%\n");

	ft_printf("m % Z\n", "test");
	printf("t % Z\n", "test");

	ft_printf("m % Z \n", "test");
	printf("t % Z \n", "test");

	ft_printf("m % Z%s\n", "test");
	printf("t % Z%s\n", "test");

	ft_printf("m %000   %\n", "test");
	printf("t %000   %\n", "test");

	ft_printf("m %%%\n", "test");
	printf("t %%%\n", "test");

	ft_printf("m %jx\n", 4294967296);
	printf("t %jx\n", 4294967296);

	ft_printf("m %jx\n", -4294967296);
	printf("t %jx\n", -4294967296);

	ft_printf("m %jx\n", -4294967297);
	printf("t %jx\n", -4294967297);

	ft_printf("m %ll#x\n", 9223372036854775807);
	printf("t %ll#x\n", 9223372036854775807);

	ft_printf("m %-010s is a string\n", "this");
	printf("t %-010s is a string\n", "this");

	ft_printf("m % Z\n", 42);
	printf("t % Z\n", 42);

	ft_printf("m %5+d\n", 42);
	printf("t %5+d\n", 42);

	ft_printf("m %5+d\n", -42);
	printf("t %5+d\n", -42);

	ft_printf("m %-5+d\n", 42);
	printf("t %-5+d\n", 42);

	ft_printf("m %-0+5d\n", 42);
	printf("t %-0+5d\n", 42);

	ft_printf("m %-5+d\n", -42);
	printf("t %-5+d\n", -42);

	ft_printf("m %-0+5d\n", -42);
	printf("t %-0+5d\n", -42);

	ft_printf("m %jd\n", 9223372036854775807);
	printf("t %jd\n", 9223372036854775807);

	ft_printf("m %jd\n", -9223372036854775808);
	printf("t %jd\n", -9223372036854775808);

	ft_printf("m %zd\n", 4294967295);
	printf("t %zd\n", 4294967295);

	ft_printf("m %zd\n", 4294967296);
	printf("t %zd\n", 4294967296);

	ft_printf("m %ju\n", 4999999999);
	printf("t %ju\n", 4999999999);

	ft_printf("m %ju\n", 4294967296);
	printf("t %ju\n", 4294967296);

	ft_printf("m %hU\n", 4294967296);
	printf("t %hU\n", 4294967296);

	ft_printf("m %U\n", 4294967296);
	printf("t %U\n", 4294967296);

	ft_printf("m %zhd\n", 4294967296);
	printf("t %zhd\n", 4294967296);

	ft_printf("m %jzd\n", 9223372036854775807);
	printf("t %jzd\n", 9223372036854775807);

	ft_printf("m %jhd\n", 9223372036854775807);
	printf("t %jhd\n", 9223372036854775807);

	ft_printf("m %lhl\n", 9223372036854775807);
	printf("t %lhl\n", 9223372036854775807);

	ft_printf("m %lhlz\n", 9223372036854775807);
	printf("t %lhlz\n", 9223372036854775807);

	ft_printf("m %zj\n", 9223372036854775807);
	printf("t %zj\n", 9223372036854775807);

	ft_printf("m %lhh\n", 2147483647);
	printf("t %lhh\n", 2147483647);

	ft_printf("m @main_ftprintf: %####0000 33..1..#00d\n", 256);
	printf("t @main_ftprintf: %####0000 33..1..#00d\n", 256);

	ft_printf("m @main_ftprintf: %####0000 33..1d\n", 256);
	printf("t @main_ftprintf: %####0000 33..1d\n", 256);

	ft_printf("m @main_ftprintf: %###-#0000 33...12..#0+0d\n", 256);
	printf("t @main_ftprintf: %###-#0000 33...12..#0+0d\n", 256);
*/

/*
ft_printf("%%");
ft_printf("\n");
printf("%%");
printf("\n");
*/

// newly failed tests

/*
ft_printf("%   %\n", "test");
printf("%   %\n", "test");

ft_printf("%x\n", 4294967296);
printf("%x\n", 4294967296);

ft_printf("%X\n", 4294967296);
printf("%X\n", 4294967296);

ft_printf("%010x\n", 542);
printf("%010x\n", 542);

ft_printf("%.2x\n", 5427);
printf("%.2x\n", 5427);

ft_printf("%5.2x\n", 5427);
printf("%5.2x\n", 5427);

ft_printf("%#llx\n", 9223372036854775807);
printf("%#llx\n", 9223372036854775807);

ft_printf("%#8x\n", 42);
printf("%#8x\n", 42);

ft_printf("%#-08x\n", 42);
printf("%#-08x\n", 42);

ft_printf("%.2s is a string\n", "this");
printf("%.2s is a string\n", "this");

ft_printf("%5.2s is a string\n", "this");
printf("%5.2s is a string\n", "this");

ft_printf("%.2s is a string\n", "");
printf("%.2s is a string\n", "");

ft_printf("%-.2s is a string\n", "this");
printf("%-.2s is a string\n", "this");

ft_printf("%-5.2s is a string\n", "this");
printf("%-5.2s is a string\n", "this");

ft_printf("%-.2s is a string\n", "");
printf("%-.2s is a string\n", "");

ft_printf("%.2c\n", NULL);
printf("%.2c\n", NULL);

ft_printf("@moulitest: %c\n", 0);
printf("@moulitest: %c\n", 0);

ft_printf("%2c\n", 0);
printf("%2c\n", 0);

ft_printf("null %c and text\n", 0);
printf("null %c and text\n", 0);

ft_printf("% c\n", 0);
printf("% c\n", 0);

ft_printf("%05o\n", 42);
printf("%05o\n", 42);

ft_printf("%5d\n", 42); //too much space at end
printf("%5d\n", 42);

ft_printf("%5d\n", -42); //too much space at end
printf("%5d\n", -42);

ft_printf("%05d\n", -42);
printf("%05d\n", -42);

ft_printf("%0+5d\n", -42);
printf("%0+5d\n", -42);

ft_printf("%-5d\n", -42);
printf("%-5d\n", -42);

ft_printf("%-05d\n", -42);
printf("%-05d\n", -42);

ft_printf("%hhd\n", 128);
printf("%hhd\n", 128);

ft_printf("%hhd\n", -129);
printf("%hhd\n", -129);

ft_printf("%lld\n", -9223372036854775808);
printf("%lld\n", -9223372036854775808);

ft_printf("%.2d\n", 4242);
printf("%.2d\n", 4242);

ft_printf("% 10.5d\n", 4242);
printf("% 10.5d\n", 4242);

ft_printf("%+10.5d\n", 4242);
printf("%+10.5d\n", 4242);

ft_printf("%-+10.5d\n", 4242);
printf("%-+10.5d\n", 4242);

ft_printf("@moulitest: %.d %.0d\n", 42, 43);
printf("@moulitest: %.d %.0d\n", 42, 43);
*/
//ft_printf("@moulitest: %5.d %5.0d\n", 0, 0);
//printf("@moulitest: %5.d %5.0d\n", 0, 0);

/*
ft_printf("%x", -42);
printf("\n");
printf("%x", -42);
printf("\n");

ft_printf("%X", -42);
printf("\n");
printf("%X", -42);
printf("\n");

ft_printf("%x", 4294967296);
printf("\n");
printf("%x", 4294967296);
printf("\n");

ft_printf("%X", 4294967296);
printf("\n");
printf("%X", 4294967296);
printf("\n");

ft_printf("%10x", 42);
printf("\n");
printf("%10x", 42);
printf("\n");

ft_printf("%-10x", 42);
printf("\n");
printf("%-10x", 42);
printf("\n");

ft_printf("%lx", 4294967296);
printf("\n");
printf("%lx", 4294967296);
printf("\n");

ft_printf("%llX", 4294967296);
printf("\n");
ft_printf("%llX", 4294967296);
printf("\n");

ft_printf("%hx", 4294967296);
printf("\n");
ft_printf("%hx", 4294967296);
printf("\n");

ft_printf("%hhX", 4294967296);
printf("\n");
ft_printf("%hhX", 4294967296);
printf("\n");

ft_printf("%llx", 9223372036854775807);
printf("\n");
ft_printf("%llx", 9223372036854775807);
printf("\n");

ft_printf("%llx", 9223372036854775808);
printf("\n");
ft_printf("%llx", 9223372036854775808);
printf("\n");

ft_printf("%010x", 542);
printf("\n");
ft_printf("%010x", 542);
printf("\n");

ft_printf("%-15x", 542);
printf("\n");
ft_printf("%-15x", 542);
printf("\n");

ft_printf("%5.2x", 5427);
printf("\n");
ft_printf("%5.2x", 5427);
printf("\n");

ft_printf("%#llx", 9223372036854775807);
printf("\n");
ft_printf("%#llx", 9223372036854775807);
printf("\n");

ft_printf("%#x", 0);
printf("\n");
ft_printf("%#x", 0);
printf("\n");

ft_printf("%#X", 42);
printf("\n");
ft_printf("%#X", 42);
printf("\n");

ft_printf("%#8x", 42);
printf("\n");
ft_printf("%#8x", 42);
printf("\n");

ft_printf("%#08x", 42);
printf("\n");
ft_printf("%#08x", 42);
printf("\n");

ft_printf("%#-08x", 42);
printf("\n");
ft_printf("%#-08x", 42);
printf("\n");

ft_printf("@moulitest: %#.x %#.0x", 0, 0);
printf("\n");
ft_printf("@moulitest: %#.x %#.0x", 0, 0);
printf("\n");

ft_printf("@moulitest: %.x %.0x", 0, 0);
printf("\n");
ft_printf("@moulitest: %.x %.0x", 0, 0);
printf("\n");

ft_printf("@moulitest: %5.x %5.0x", 0, 0);
printf("\n");
ft_printf("@moulitest: %5.x %5.0x", 0, 0);
printf("\n");
*/


// coudln't figure out, basically works
//ft_printf("%x", -42);
//printf("\n");
//printf("%x", -42);
//printf("\n");

// can't figure out, basically works
//ft_printf("%lx", 4294967296);
//printf("\n");
//printf("%lx", 4294967296);
//printf("\n");

// I don't know how this works, to make it work breaks how normal things work
//ft_printf("%5.2x", 5427);
//printf("\n");
//printf("%5.2x", 5427);
//printf("\n");

//ft_printf("%-5.2s is a string", "this"); //basically works, not sure what's wrong
//printf("\n");
//printf("%-5.2s is a string", "this");
//printf("\n");

//ft_printf("%5.2s is a string", "this"); //basically works, not sure what's wrong
//printf("\n");
//printf("%5.2s is a string", "this");
//printf("\n");

//ft_printf("%-#6o", 2500); //I have no idea what the exception for this is
//printf("\n");
//printf("%-#6o", 2500);
//printf("\n");

//ft_printf("%5d", 42); //essentially works, no idea what's going on here
//printf("\n");
//printf("%5d", 42);
//printf("\n");

//ft_printf("%u", -1); //essentially works, no idea what's going on here
//printf("\n");
//printf("%u", -1);
//printf("\n");

ft_printf("%hhd", -129);
printf("\n");
printf("%hhd", -129);
printf("\n");

    return(0);
}
