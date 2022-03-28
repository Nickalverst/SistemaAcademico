class Horario
{
private:
    int hora;
    int min;
public:
    Horario(int nHora, int nMin);
    int getHora();
    int getMin();
    void setHora(int novaHora);
    void setMin(int novoMin);
    int calcularIntervalo(Horario b);
};
