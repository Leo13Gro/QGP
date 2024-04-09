#include <iostream>
#include <cmath>
#include <ROOT/RDataFrame.hxx>

void createDf(){
    ROOT::RDataFrame d(1000);

    auto r = new TRandom();

    double const A = 197;
    double const R = 1.25 * pow(A, 1./3);
    auto bLinear = new TF1("f1", "x", 0, 2*R);
//    std::cout << bLinear->GetRandom(0, 2*R);

    auto dd =  d
            .Define("Psi_RP", [&r](){return r->Rndm() * 2 * M_PI - M_PI;})
            .Define("b", [&bLinear](){return bLinear->GetRandom();})
            ;
    std::cout << dd.Describe() << std:: endl;
    auto out = dd.Display();
    out->Print();
//    dd.Snapshot("t", "out_file.root");
    std::vector<ROOT::RDF::RResultPtr<TH1D>> h1;
    h1.push_back(dd.Histo1D({"h_Psi_RP", "Psi RP", 100, -3.15, 3.15}, "Psi_RP"));
    h1.push_back(dd.Histo1D({"h_b", "Impact parameter", 100, 0, 2*R}, "b"));

    auto c = new TCanvas();
    for (int i = 0; i < h1.size(); ++i){
        h1.at(i)->Draw();
        c->SaveAs(("hist/" + std::to_string(i) + ".png").c_str());
    }
}