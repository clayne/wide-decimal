///////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2020 - 2022.                 //
//  Distributed under the Boost Software License,                //
//  Version 1.0. (See accompanying file LICENSE_1_0.txt          //
//  or copy at http://www.boost.org/LICENSE_1_0.txt)             //
///////////////////////////////////////////////////////////////////

#include <math/wide_decimal/decwide_t.h>
#include <math/wide_decimal/decwide_t_examples.h>

auto math::wide_decimal::example001b_roots_almost_integer() -> bool
{
  constexpr std::uint32_t wide_decimal_digits10 = UINT32_C(5001);

  using dec5001_t = math::wide_decimal::decwide_t<wide_decimal_digits10>;

  // Consider a fascinating number.
  const dec5001_t term = dec5001_t(27U) + (sqrt(dec5001_t(69)) * 3U);

  const dec5001_t p    = pow(cbrt(2 / term) + (cbrt(term / 2) / 3), 23456U);

  // N[((2/(27 + 3 Sqrt[69]))^(1/3) + (1/3) ((27 + 3 Sqrt[69])/2)^(1/3))^23456, 5003]
  // The exact page at Wolftam Alpha that can calculate this number is:
  // https://www.wolframalpha.com/input/?i=N%5B%28%282%2F%2827+%2B+3+Sqrt%5B69%5D%29%29%5E%281%2F3%29+%2B+%281%2F++++++++3%29+%28%2827+%2B+3+Sqrt%5B69%5D%29%2F2%29%5E%281%2F3%29%29%5E23456%2C+5003%5D

  const dec5001_t control
  {
    "3365272647886208288021998679827724704587938789178158204546222945014628019714551475681908630418039976"
    "2029278469732668988468815713205463138488238673670175626591086988674467987963835643825641039040129223"
    "8189668244184677337978092752203964423834146126119231420449506578763016892045766959069055752096621883"
    "5470103202072837959290392223496770592781439143072463883699838317162239648782950829695529577037580736"
    "5987005711361500782072316140333633391668100796546729954355137811792948882540760927348890097677920151"
    "3883531187690290103310910218776336636325631421554101593036959289601116532578799698820368743453364142"
    "9603784762391333776239043805242034732030128016392574286438977700692443938440807253328205548789709455"
    "1944801399137824527274715271171513779158549771295248955125953721730438889492976254957554410313285687"
    "7007934586243816251846386910295532593267386605799782513297680516830734525376031806229136772858632626"
    "3848570744312211200236117132524502606410465157264104658083257439718301003793120767228183836423848490"
    "7068105078529547716896423248326340644068870534779536821345701006748565975860510636547825998542669739"
    "9448057800023232499239236238513172427131747309129580526087995458852123002820427843333866592048607434"
    "7820325263919988560368322703612488745995916873468110725854193237564829137040317884202767010842045224"
    "2769977758246356327175487629284774765899666929587623151304680975685927038032126191272795153848706307"
    "0232774111708020843258050740638399366341998249173165706901652344541008962663977260815687925017745536"
    "2764180582806544802997718849882450205283982343269595516642290973521735036618097914918506178155378780"
    "1149977342964254375702226124599763562319006234529568535081758609575537941294960313975106211875204034"
    "8888779314572817014592399202620203565267052453021931136222084773872330531974240679493698634453637348"
    "7991307014739070382299881545965539025398324567579136437668387308337620824123601836788055442913725618"
    "2905500083223888983117244817198384700761392614420515068144810797381131524259229308781102232153861809"
    "9683557418728821341488129958547062986789639316994092405158414751728124822908218921406962744622353205"
    "4937379625707658176391320908750196350891233263315734669851153283605570190412520451614126185910540311"
    "6002782387484643802184597743020170301540997107943131741612266829643127055905017704873617467890973489"
    "7021247319099441624984997419817530407522004871452533673922445679894324790019074845713201246381081524"
    "0760390569440839518539334270852518667192433742090048980214328644250494332139468084373586821468671048"
    "9873610005286064421146542005215337154340913505110091213599384779700780529672367699370164188042297059"
    "0266151417802934903831264273578946157734915592372729170317187448823558950102996949577496335207963475"
    "4329040863236117083469927696940000839137408660193674330846748358459350720560047719177618688625978231"
    "66427615523064871081751258339762420569697332640790854245608990245.0000000000000000000000000000000000"
    "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
    "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
    "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
    "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
    "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
    "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
    "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
    "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
    "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
    "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
    "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
    "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
    "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
    "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000088"
    "9015137206924671881859532143841689475856459178269188789116371713615507838174359608521723414516548928"
    "2153036550602728033710670190963828122627960484785370928051386161732939990017397839932304948955605524"
    "3572738796434654583397349285476291789888610681695384425351900392126232497218514708524583704384159057"
    "8856127943164729155827094146361165269737877914796271271949076550604291580219104259411526970827562202"
    "5346293420039355242641697899468555988194340522101802892919007330390478267986013499161451624715470661"
    "4876214660201658962863949145028174889283262591914692497478019115412149117807836982925412822404282892"
    "6860749281375762034668804523194097167402529348656582884374390471824630340639369838296123965983495784"
    "2905"
  };

  const dec5001_t closeness = fabs(1 - fabs(p / control));

  const bool result_is_ok = closeness < (std::numeric_limits<dec5001_t>::epsilon() * 10);

  return result_is_ok;
}

// Enable this if you would like to activate this main() as a standalone example.
#if 0

#include <iomanip>
#include <iostream>

int main()
{
  const bool result_is_ok = math::wide_decimal::example001b_roots_almost_integer();

  std::cout << "result_is_ok: " << std::boolalpha << result_is_ok << std::endl;
}

#endif
