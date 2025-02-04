#include "idaTypes.h"
#include "actor.h"

extern const char   aJiraiC[];

extern int          jirai_act_8006AB5C(int a1);
extern int          jirai_kill_8006B05C(int a1);
extern int          jirai_loader_8006B564(struct Actor *pActor, int a2, int a3);

struct Actor *NewScenarioJirai_8006B76C(int arg0, int arg1)
{
    struct Actor *actor;

    actor = GV_NewActor_800150E4(6, 0x154);
    if (actor)
    {
        GV_SetNamedActor_8001514C(actor,
                            (TActorFunction)&jirai_act_8006AB5C,
                            (TActorFunction)&jirai_kill_8006B05C,
                            aJiraiC);
        if (jirai_loader_8006B564(actor, arg0, arg1) < 0)
        {
            GV_DestroyActor_800151C8(actor);
            return 0;
        }
    }
    return actor;
}
