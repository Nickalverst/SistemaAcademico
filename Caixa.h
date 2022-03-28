class Caixa
{
private:
    float altura;
    float largura;
    float profundidade;

public:
    Caixa(float altura, float largura, float profundidade);
    void setLargura(float nLargura);
    void setAltura(float nAltura);
    void setProfundidade(float nProfundidade);
    float calcularAreaExt();
    float calcularVolume();
};
