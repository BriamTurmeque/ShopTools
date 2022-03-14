Purshaced
{
    vector <Tools*> purshacedTools;
public:
    Purshaced()
    {
        purshacedTools = {};
    }
    purshacedTools(vector <Tools*> Tools)
    {
        purshacedTools = Tools;
    }
    void agregarHerramientas(Tools* h)
    {
        purshacedTools.push_back(h);
    }
};
