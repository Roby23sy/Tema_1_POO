#include "Meciuri.h"

    Meciuri::Meciuri()
        {
            First = NULL;

            Second = NULL;

            next = NULL;
        }


    Team* Meciuri::get_First()
        {
            return First;
        }


    Team* Meciuri::get_Second()
        {
            return Second;
        }

    void Meciuri::set_First(Team* te)
        {
            First = te;

        }



    void Meciuri::set_Second(Team* te)
        {
            Second = te;
        }


    Team* Meciuri::get_win()
        {
            if(First->get_punctaj() > Second->get_punctaj())
                    return First;
            else
                return Second;

        }


    Team* Meciuri::get_lose()
        {

            if(First->get_punctaj() > Second->get_punctaj())
                    return Second;
            else
                return First;

        }

    void Meciuri::point_at_next(Meciuri* mec)
        {
            next = mec;
        }


    Meciuri* Meciuri::get_next()
        {
            return next;
        }


