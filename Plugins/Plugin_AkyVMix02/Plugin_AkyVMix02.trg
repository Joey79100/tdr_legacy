;------------------ Section for flipeffect trigger: description of the trigger -------------------------------
<START_TRIGGERWHAT_9_O_H>
585:Enemy. Remove the shadow of <&> enemy type (or Lara) for (E) case #REMARK#Click on [Trigger's Help] button for more infos.#START_DOC#
You can have maximum five enemy types at the same time, with shadow removed. That is why you have five "cases" as parameters. You need to add a different "case" to each case when you remove a shadow of an enemy.
A case ID can be re-used at the next time in that level, even for another enemy type, only if you have already restored (see F586) the shadow of the previous enemy with that case ID.
#END_DOC#
586:Enemy. Restore the shadow of <&> enemy type (or Lara) for (E) case #REMARK#Click on [Trigger's Help] button for more infos.#START_DOC#
For the explanation of "cases" and removing the shadow, see F585.

Important!
You need to add the same case to the restoration of an enemy what you added to its removal.
#END_DOC#
587:Variables. Execute <&> operation #REMARK#Click on [Trigger's Help] button for more infos.#START_DOC#
This is the trigger if you want this:

- Executing all the general variable triggers of Paolone (set, add, subtract, multiply, divide, for values of variables or memory zone fields or setting/clearing bits, also adjusting the memory zone subject) at one place.
- All the routes (number to variable, number to memory zone field, variable value to another variable, variable value to a memory zone field, memory zone field value to another memory zone field) are available.
- You can transport level values into the title or vice verse.
- New operations (raise to any power, square root) are added.
- 45 brand new "long" local and 45 brand new "long" global (integer) variables are added.
- Handling floating values are possible, as pure numbers or with brand new huge (further 5 local and 5 global) variables.
- The remainder of the division can be stored.

See more in NG Center/Reference/Mnemonic Constants/PARAM_VAR_MASTER.

If you'd like to check the "new" variables or the "old" memory zone fields, then see C114 for a condition trigger, F588 for the diagnostic screen or F589 for the log.
For "old" variables in diagnostic/log/condition, see the triggers/Script commands of trng.dll.
#END_DOC#
588:Variables. Diagnostic. (E) Enable/disable <&> diagnostic #REMARK#Click on [Trigger's Help] button for more infos.#START_DOC#
This trigger is useful in these cases:

- See F587 trigger for new variables. Now they can have their own diagnostic screen as well.
- Till now, there was no a diagnostic screen for the memory zone fields, you could check them only copy/pasting them in old variables, seeing the diagnostic screen of the old variables.
-You can also check on the screen now even if the new variables have a bit set or clear.

See more in NG Center/Reference/Mnemonic Constants/PARAM_DIAGNOSTIC.

---------- Notes: ----------

- If you want to enable another diagnostic screen, with different contents, then you don't need to disable the previous one just being showed, just enable the new one, to also remove the previous one.
- If you want to disable the diagnostic screen, not showing another one after that, choosing "disable" in the trigger, then you can choose anything in the <&> field.
- If a diagnostic screen is enabled, then (either you swap it for another one later or not) it will follow you all the way, through menus, loadscreens, other levels, even back to title. The only way to remove it is:

a, a disabling F588 trigger, or
b, leave the level without having the enabling F588 activated and saved in a savegame, or
c, leave the game in the title.

- See F598 of this plugin if the game stops drawing these diagnostics while showing static or flyby camera screens.
- These diagnostic screens have no effect on classic trng.dll diagnostic screens, and vice verse.
As opposed to these new plugin screens, trng.dll screens
a, cannot be switched on, off or changed during the game, they are always showed while the game running, with constant contents, and
b, they are not active during loadscreens or menus. (See F593 of this plugin to control the new diagnostic screens during menus or loadscreens.)

----------------------------

Buggy memory zone field properties (controlled by trng.dll, not the plugin, so I cannot fix it):

- Please accept that some memory zone field values are not saved in savegames.
So after saving/loading, the diagnostic screen may show a false data about some fields. (That is why I suggest following memory zone values on the diagnostic only that happened after loading savegame/level the last time. - Or you need eg. a GlobalTrigger to restore the data in that field after loading.)
- Some data can be fake if it is just not happenning. (Eg. found item index has a fake value before founding any item.)
- As the name says, some savegame memory values will be updated only when you save the game.
- Some memory zone fields will work successfully only under special circumstances. Like eg. the fog color of savegame memory will work only with trigger-refreshed colors, not accepting the value if that was created by a Fog Script command.
- Some data will keep its last value even after not refreshing it any more, even if its property itself is not presented any more.
#END_DOC#
589:Variables. Log. Print <&> value in the log #REMARK#Click on [Trigger's Help] button for more infos.#START_DOC#
See F588. The data mentioned there, can be also showed in the log.
First of all, you should use the log instead of diagnostics, if a data on the diagnostic screen changes too fast, so you cannot follow it properly. On the other hand, if the log is running while you are running the game, using F589 to record a data in the log, then:

- it is easier to follow the data on the log screen (the game should be in windowed mode now), or
- if the log screen is still too fast, then, after closing the game an the log screen, you can use the TXT - always made from the latest log screen contents, placed in Tools folder - to follow the data (saved there) easily.

See F590 to remove the chosen entry from being recorded in the running log.

---------- Notes: ----------
- If you activated an F589 to print a log record into the log, and you don't close the log window, then that record will be continuously printed all the way into the log, through menus, loadscreens, other levels, even back to title. The only way to remove it is (if you still don't want to close the log window):

a, a disabling F590 trigger, or
b, leave the level without having the enabling F589 activated and saved in a savegame, or
c, leave the game in the title.

- See F593 of this plugin to control printing the log records during menus or loadscreens.
- See F598 of this plugin if the game stops writing the records in the log while showing static or flyby camera screens.
- For printing the "old" variables in the log, see F309 of trng.dll.

----------------------------
#END_DOC#
590:Variables. Log. Remove <&> value from the log #REMARK#See F589 of this plugin for more infos.
591:Text. (E) Print/remove custom text and variable with <&> parameters #REMARK#Click on [Trigger's Help] button for more infos.#START_DOC#
This trigger is useful in these cases:

- See F587 trigger for new variables. Now you can print their values on the screen, even with some custom text together as well.
- Till now, there was no a possibility to print a memory zone field on the screen directly, even with some custom text together as well. I mean, till now, you could print only the old variables, into which you copied the field values previously.

See more in NG Center/Reference/Mnemonic Constants/PARAM_PRINT_VAR.

---------- Notes: -----------

- Classic trng.dll printing triggers enable only constant text positions (or perhaps regularly scrolled texts), which is not always enough. This F591 trigger lets you show even variable-based text positions - i.e. only one trigger for one text, where you can change the text coordinate. 
- If you activated an F591 to print a text, then it will be continuously printed all the way, through menus, loadscreens, other levels, even back to title. The only way to remove it is:

a, a disabling F591 trigger, or
b, leave the level without having the enabling F591 activated and saved in a savegame, or
c, leave the game in the title.

- You need to disable the text (at latest when the Finish trigger is activated) with another F591, if you don't want to print the text in the next level.
- See F593 of this plugin to control printing the texts with F591 during menus or loadscreens. (So eg. you can remove a text when a menu is open and you will restore it if it will close again later.)
Even if you don't want to print new variable or memory zone field values - and this is something that is good to know, because F591 the only useable printing trigger under menus or loadscreens!
Two examples:

a, You want to print the text only in real game time, not in menus or loadscreens, so you need an F591 in an F593 that suspends the text in all the menus/loadscreens, if they are on, and another F591 in another F593 that restores it if all the menus/loadscreens are off. (The first print out of the menus/loadscreens will be naturally executed when the "restoring" trigger is activated.)
b, You want to print the text only during the inventory and its sub-menus (save/load game menus opening from inventory, plus the Examine item display), so  you need an F591 in an F593 that prints the text in inventory+submenus, if they are on, and another F591 in another F593 that removes it if inventory+submenus are off.

- If you need a blinking text (again, either you want new variables/memory zone fields or not), then use F591 everyway with F593, using the loop feature of F593. (Yes, F593 is for menus/loadscreens, but your setup will simply be "if there is no menu/loadscreen" now.)
- See F598 of this plugin if the game stops printing these texts while showing static or flyby camera screens.

----------------------------
#END_DOC#
592:Finish. Load <&>level to (E) Lara #REMARK#Click on [Trigger's Help] button for more infos.#START_DOC#
This trigger first of all is a simple reproduction of a casual "Finish" trigger. However, it can be useful in these two cases:

- The exportable version of the classic FINISH trigger (trng.dll F82) cannot make a level jump to a LARA_START_POS object, but the classic FINISH and this F592 can. So use this trigger if you want an exported version of a level jump to a LARA_START_POS, instead of LARA object.
- F593 to check the level jump loadscreen is available only with this Finish trigger (either Lara or a LARA_START_POS). Either classic FINISH or F82 cannot do that.

---------- Note: -----------

Just like FINISH or F82, F592 can also make a level jump to the title. The solution is the same with all the three triggers:

X = A + Z

Z is minimum 2, but could be any bigger number.

If your level amount is A, then you need to choose X (= A + 2) in the the trigger to load you back to the title.
For example, having five levels, you need to choose Level 7 (= 5 + 2) in the trigger.

In the case of 592, it doesn't matter if you choose Lara object or any LARA_START_POS now.

----------------------------
#END_DOC#

593:TriggerGroup. Perform trigger in menu mode with <&> parameter #REMARK#Click on [Trigger's Help] button for more infos.#START_DOC#
This trigger lets you activate triggers during menus or loadscreens.

How does it work?
Well, first an F593 needs to be placed, either as a local trigger in the map, or as a GlobalTrigger in the Script. Not in the required menu, naturally, that is impossible, but in the real gametime phase, BEFORE opening that menu.
So, if you want, FROM NOW ON, a menu trigger to be activated if the player opens the required menu, then place that F593. If the player, AFTER activating that F593, opens that menu THE NEXT TIME, then the required "menu trigger" will be activated.

Hitting a keyboard key during menus or loadscreens or the inner timer of the menu are also included as options to enable triggers.

Some examples when this trigger can be useful:
- You can print any drawn thing (eg. a custom text) on the screen only when the required menu is on, removing it when the menu closes. (Important! As far as I can see, the drawing features of my plugin will surely work for this, but classic trng.dll features will not. For example, you can print a custom text for new variables with F591 in the menu, but trng.dll printing triggers are useless for that. That is why I suggest using F591 to print a custom text in a menu, even if you don't want to print a new variable with it. - You will definitely find several trng.dll triggers which cannot be executed during menus/loadscreens!)
- You can change the amount of an inventory item, if you hit a key when inventory is on (activating an inventory flipeffect for the amount).
- Spawning a baddy when a menu is open naturally will not happen, because the game is suspended when the menus are open. But if you make a setup for that, then the trigger will be executed in the background, and will be realized in the game when that menu closes. (Maybe you can make it clear for yourself if the spawning trigger will be directly executed by closing that menu in your setup, not opening that.)
- Etc.

Important!
If you have a TRNG savegame panel at a level (instead of the classic savegame list), then do not use this feature on that level, for the savegame panel and the adjacent menus. (Adjacent menu eg. the inventory main menu - this is whereto you step back with ESC, from the savegame panel.) Otherwise the feature will work in a buggy way during the panel and those menus.
On those levels probably you should use this feature only in Paused menu and its submenus, plus the loadscreens.
(I will try to fix it a latter plugin update, if I can.)

See more in NG Center/Reference/Mnemonic Constants/PARAM_MENU_TRIGGER.

---------- Notes: -----------

- The working is a bit different with title menus, because local and global triggers work in their cases, when the menus are on. The menu trigger now can be triggered even if the required menu is just on when F593 is triggered, the menu trigger will be naturally triggered right away now.
- In many aspects, mostly with the inventory triggers, it is not compatible (yet?) with JMN's ring inventory plugin, causing the game crashes.

----------------------------
#END_DOC#
594:Backup. Restore (load) the <&> backup file in (E) way (for menu mode)#REMARK#Click on [Trigger's Help] button for more infos.#START_DOC#
This trigger first of all is a simple reproduction of trng.dll F98 trigger. However, only this one is useable to detect a backup loadscreen for F593 triggers.

---------- Note: -----------

"Black screen" option is probably unuseable if you want to draw things (text, image etc.) on the screen while the loadscreen is seeable.

----------------------------
#END_DOC#
595:Sprite. (E) Show/hide sprite with <&> parameters #REMARK#Click on [Trigger's Help] button for more infos.#START_DOC#
PARAM_SHOW_SPRITE of trng.dll enables only constant sprite positions, which is not always enough. This F595 trigger lets you show even variable-based sprite positions - i.e. only one trigger for one sprite, where you can change the sprite coordinate. 
Plus, F595 can make the sprite fade in or out.

Besides, F595 (either with constant or variable-based coordinates) is able to show the sprites properly under menus or loadscreens - because trng.dll sprite triggers cannot do that.

See more in NG Center/Reference/Mnemonic Constants/PARAM_SPRITE_DISPLAY.

---------- Notes: -----------

- If you choose a non-constant presence for a sprite, i.e. fading-in, timer or fading-out, then, when you want to hide the sprite, that will happen immediately everyway, even having a setup with fading-out, if any of those fading-in, timer or fading-out procedures is just being performed.
- After placing it on the screen, the sprite will not leave it in that level, till you hide it. Which means the sprite will be on the screen even during menus or loadscreens. See F593 of this plugin to control the presence of the sprites during menus or loadscreens.
- See F598 of this plugin if the game stops drawing these sprites while showing static or flyby camera screens.

----------------------------
#END_DOC#
596:Sprite. (E) Enable/disable "raindrops on lens" effect with <&> parameters #REMARK#Click on [Trigger's Help] button for more infos.#START_DOC#
This trigger will place randomly several "raindrop" sprites on the screen, simulating marks of raindrops (or snowflakes) on the camera lens, in rooms where it is raining or snowing, or close to waterfalls.

This is how it works:

If you enable this feature with this trigger, then:
- enabled it in a room where it is not raining/snowing, and/or when Lara is not close to waterfalls: the effect starts only later, when she enters a room where it is raining/snowing, and/or when she gets close to a waterfall, or
- enabled it in a room where it is raining/snowing and/or when Lara is close to a waterfall: the effect starts immediately.

When the effect starts, it makes the first mark show up on the screen, in a random position. When the time is getting on, more and more marks show up in random positions on the screen. If the amount of the marks reaches the maximum, then it will be constant after that: if the next mark shows up, then the oldest mark on the screen will be removed ("dried off").

If Lara leaves the room where it is raining/snowing (and/or gets farther from waterfalls), then no more marks will be placed on the screen. However, the actual marks on the screen will be removed now, one after the other (first the oldest ones) - then they will show up there again if she goes into those rainy/snowy rooms again and/or if she gets close to waterfalls again.

If Lara goes under the water surface, then that water will wipe all the marks immediately off the screen.

If you disable the effect with another F596, then you can choose how the marks still on the screen will be wiped off. ("Disable" is more than "if Lara leaves the rainy room then the raindrops will be wiped off". If you disable the effect, then the raindrops naturally won't be put on the screen again if Lara goes back to the rainy room.)

Important!
- The setup will work for rainy rooms only in RAIN_SINGLE_ROOMS case, i.e. if the rainy room both has "outside" and "rain" flag.
The setup will work for snowy rooms only in SNOW_SINGLE_ROOM case, i.e. if the snowy room both has "outside" and "snow" flag.
- You need to use customized images for binoculars/lasersight layout, with CUST_BACKGROUND.
If you use the classic BINOCULAR_GRAPHICS and TARGET_GRAPHICS for them, then the raindrops will be seeable on the screen even when they should be covered by the graphic parts.

See more in NG Center/Reference/Mnemonic Constants/PARAM_RAINDROP.

---------- Notes: ----------

- Instead of the usual triggers, use F592 for level jumps and F594 for loading backup savegames, or else the raindrops won't be hide while you can see the loadscreens of these features.
- See F598 of this plugin if the game stops drawing these raindrop sprites while showing static or flyby camera screens.
- Not only raindrops, snowflakes and waterfalls are useable in this setup. PARAM_RAINDROP will tell you how to use it eg. in the case of "splashing blood drops on the camera lens" etc.
- The rain/snow in a room has a few tiny conditions as well, to see rain/snow there. For example, at least one "transparent texture" tile (which must be placed usually where you want to see horizon) is also needed in a room like that, to see rain/snow there. So be careful, these tiny conditions must also be true in "outside" rooms or else you will see raindrop marks there (if this feature is enabled), but you won't see the rain/snow itself there.
- Just think about this situation: "if Lara and Lara's camera are too far from each other, then perhaps this false thing will happen: Lara has just stepped into the rainy room, but the camera is far behind her, still not getting into that room". If the screen already had raindrop marks, that would be ugly now, that is why not Lara herself but her camera detects the raindrop situations.

----------------------------

How will the static and flyby cameras be handled (because they don't belong to Lara)?
Well, all about them are automatical, if you also keep all of this in your mind:

First of all, there are four basic situations:
- Lara is in rain (or snow, waterfall, I won't recite it again and again), static/flyby is too (in another rainy room or in the same one).
- Lara is in rain, static/flyby is not.
- Lara is NOT in rain, static/flyby is.
- Lara is NOT in rain, static/flyby is not, either (in another non-rainy room or in the same one).

The basic statement is, static/flyby cameras are "being spawned" in the moment, when the screen swaps for them. Which means, even if it keeps raining in the room where that camera is. So, when the camera is activated, it is not full of raindrops (saying, "the camera has been here since ages in the rain, so there should be several raindrops on it"), but that is the moment when the first raindrops will be "drawn" on it.

So these things will happen:
- Rainy Lara swaps for rainy static/flyby: the X (actual) amount of raindrops in random arrangement on Lara's camera will be swapped for a full clear static/flyby camera, where the raindrops start show up now, in a brand new random arrangement.
- Rainy Lara swaps for non-rainy static/flyby: the X (actual) amount of raindrops in random arrangement on Lara's camera will be swapped for a full clear static/flyby camera.
- Non-rainy Lara swaps for rainy static/flyby: the full clear Lara's camera screen will be swapped for a full clear static/flyby camera, where the raindrops start show up now, in a brand new random arrangement.
- Non-rainy Lara swaps for non-rainy static/flyby: the full clear Lara's camera screen will be swapped for a full clear static/flyby camera.

And then, if it is a flyby camera:
The raindrops on the camera will be kept/removed/placed exactly in the way as if Lara herself move between rooms, and as if it is her camera, not a flyby one.

If the flyby sequence will be ended/aborted, or if the static camera will expire/be aborted, so if we swap back for Lara's camera, then it happens in the similar way as I described above.
For example, if a rainy static camera swaps back to a dry Lara's camera, then all the raindrops will be wiped suddenly off the screen.
But we make the things easier now. I mean, for example, this should be a logical procedure from the beginnings:

1. Lara is in a rainy room, having X amount of raindrops on the screen.
2. Then a static camera is activated with maximum amount of raindrops on the screen.
3. The static camera is still shooting, but Lara leaves the rainy rooms. The raindrops on her camera is just not seeable, but they are decreasing.
4. Then the static camera is switched off, the raindrops, representing the actual, decreased amount on Lara's camera, should be restored.

It is too complicated. Now I should calculate two raindrop sequences: one for the static camera, and one for Lara. To avoid that, I used only these rules:

- if a static/flyby camera swaps back to Lara's camera (when Lara is in a rainy/snowy/waterfall area), then Lara's camera will be full clear, where the raindrops start show up now,
- if a static/flyby camera swaps back to Lara's camera (when Lara is not in a rainy/snowy/waterfall area), then Lara's camera will be full clear,
- if a static/flyby camera swaps back to Lara's camera, but they both are rainy, then the raindrops on Lara's camera will have a new random arrangement.

(All of this is  not illogical. I mean, eg. if a static camera has raindrops when swaps back for Lara'camera, still in the same room, and Lara's camera starts from 0 raindrops, then we can say eg. that "Lara's camera got dry while we are looking through the static camera, because, in the meantime Lara's camera was put away".)

In this meaning the lasersight and the binoculars work in the same way as static cameras.

Be carefu!!
- I didn't test the code for the really special camera types, like StandBy camera effect etc.
- I didn't test the code for the really special camera situations, like jumping from a flyby camera to a static camera etc.

---------- Note for cameras: ------

There can be a bit annoying, but not serious bug: unwanted raindrops on the screen. For example, if a static camera is in a rainy room, Lara's camera in a dry (= not rainy) room, then there will be raindrops on Lara's camera (more or less time - it depends on your setup values), after the screen swaps from the static camerafor Lara's camera.
To fix that bug:

- In the case of flyby cameras in rainy rooms: if Lara's camera in a dry room, then the flyby sequence should both start and end in a dry room.
- In the case of static cameras in rainy rooms: if Lara's camera in a dry room, then the static camera should not shoot at Lara, but only a Target object. If you want to shoot at Lara in the dry room, then the Target object should be between the static camera and Lara, so it looks as if it shooted at Lara, not the Target.

-----------------------------------
#END_DOC#
597:Effect. <&> Start/stop making Lara dripping for a while #REMARK#Click on [Trigger's Help] button for more infos.#START_DOC#
First with high, later with low intensity, the water starts dripping from Lara, about for 100 seconds - this is the exact way of her dripping coming out of water.

Choosing "stop" in the trigger you can abort it. (Even if it is a "normal" dripping, not generated by this trigger!)
Choosing "start" in the trigger you can restart it from the beginning, even if she is still dripping.

---------- Notes: -----------

- The "Lara is dripping" trng.dll condition (C5) is not exact, it becomes true even if she is in a pool.
The exact condition must be some kind of combination, like "Lara is dripping"+"she is not in a water room", or "Lara is dripping"+"she is not swimming/floating".
- If you would like to control the drips by being in rainy/snowy rooms or being close to waterfalls, then use F596 instead of F597.

----------------------------
#END_DOC#
598:Camera. <&> Start/stop fixing "text/image/sprite is missing from static/flyby camera screen" bug #REMARK#Click on [Trigger's Help] button for more infos.#START_DOC#
If you experience in the level that texts or sprites, printed/drawn by this plugin, are missing from static or flyby camera screens, then start this fix.

---------- Notes: ----------

- While this fix is on, I don't recommend using conditions to check if the chase or a static camera is just working. (But you can always check for flyby cameras.)
- IF_OVER_FLYBY or similar flags of trng.dll are useless now for this fix.
- Not only for this fix, but even for other features, some of IF_OVER_FLYBY or similar flags of trng.dll are found useless or buggy, when I am writing this.
If you have a similar "missing" issue with trng.dll triggers, then use those flags (even if you experience they are still useless/buggy), and, together with that, also use this F598 trigger. All of this should fix the bug for those trng.dll triggers.

----------------------------
#END_DOC#
599:Trigger management. (E) Activate/deactivate condition, signed with <&> #REMARK#Click on [Trigger's Help] button for more infos.#START_DOC#
The "TRIGGER_TRIGGERER method" is the “general condition”, you can simply disable or enable triggers with it, without naming any "real" condition.
For example, what if you want Lara to activate Trigger X only if she collected Secret No.2 in the level? – Well, then you do this:

1. You place a TRIGGER_TRIGGERER nullmesh object on the square of Trigger X.
2. Then you click on T button to create a blue frame around the square.
3. Then you adjust a common trigger for the TRIGGER_TRIGGERER in the Set Trigger Type panel.
4. Then you click on the square of SECRET trigger (having Value 2 in its “Object to trigger” box) to place the common trigger of that TRIGGER_TRIGGERER on the same square where the SECRET trigger is placed.

Okay, but that method doesn’t work in these two cases:

- If Trigger X has many squares, I mean, if the zone of Trigger X is eg. 10 squares (eg. 5×2) sized then supposedly you don’t want to place ten TRIGGER_TRIGGERER objects with ten triggers for them.
- If Trigger X is not a placed trigger but an executable trigger in a GlobalTrigger Script command.

To solve those problems, we will use a simple new method now, i.e. a new type of the “general condition”, not using TRIGGER_TRIGGERER objects or triggers for them. For example, that is how we’ll use the new method in the case if in the example above Trigger X has more squares/is a scripted trigger:

1. First, place a copy of this F599 trigger on the square where you placed that SECRET trigger. Choose "activate" in F599, plus (even randomly) choose a sign number, eg Sign 7 this time. I.e. when Lara has got the secret then the you will have an active Sign 7.
2. You have two possibilities now:

- If Trigger X is a placed trigger on more than one square:
Place one C111 trigger of this plugin, exactly overlapped with all the squares of Trigger X.
Then choose the same sign (Sign 7 now) in this C111.
So, if Lara steps on Trigger X then C111 will examine if Sign 7 is active. Trigger X cannot be activated if Sign 7 is not active, i.e. if Lara hasn’t got that secret so far.

- If Trigger X is in a GlobalTrigger, for example GlobalTrigger#1:
Type the export values of a C111 (choosing Sign 7 in it) in a brand new TriggerGroup, for example TriggerGroup#1.Then type the ID of the TriggerGroup (1) in IdConditionTriggerGroup field of the GlobalTrigger.
So, C111 in the GlobalTrigger will examine continuously if Sign 7 is active. Trigger X cannot be activated if Sign 7 is not active, i.e. if Lara hasn’t got that secret so far.

---------- Notes: ----------

- You shouldn't use the same sign in the same level, but feel free to use it in another one. (Don't forget that ResetHUB kills the triggers, when coming back to a level, including if a sign like that has already been activated.)
- Naturally that GlobalTrigger#1 is meaningless if you simply use it as I described it above, because Trigger X will be executed in the moment when you got the secret - so as if Trigger X were simply overlapped in the map with the SECRET trigger.
That is why:

a, GlobalTrigger#1 should be disabled in the moment when you got the secret, it will be enabled only later. And/or
b, GlobalTrigger#1 has at least one more condition, not only C111.

- TRIGGER_TRIGGERERs activated can be deactivated with an antitrigger, somewhere else where you originally activated them. With the same logic, C111 conditions activated can be deactivated somewhere else, choosing "deactivate" in F599, so the trigger(s) overlapped with C111 can be disabled again.

----------------------------
#END_DOC#
600:Lara. (Holds) (E) Establish/remove <&> switch sequence#REMARK#Click on [Trigger's Help] button for more infos.#START_DOC#
You can activate this trigger to establish any time in a level, but everyway at least a bit before using that switch sequence.

("Removing" a sequence is not a physical remove, it only makes the sequence unuseable. So "remove" if you are sure that you won't reach that sequence again. It has no any spectacular effect, it only frees some resources for the game engine.
Or you can "remove" temporarily, so you will "establish" the sequence again when Lara goes back to those switches.)

"Switch sequence" means Lara needs to use the switches in the required order. - Just remember the original TR4 switch sequence, i.e. the SEQUENCE_SWITCH buttons and the SEQUENCE_DOOR1 doors from the “Underneath the Sphinx” TRLR level, where you have three switches, with  with six possible acceptable solutions, to open six different doors. ("Acceptable solution" = different orders of using the switches.)

The differences are between the Last Revelation setup and this F600 one:

- The Last Revelation setup was only for one sequence. If you want, you can reproduce that once for each of your levels. But this F600 sequence lets you have even 30 sequences in each level, even at the same time. (Moreover, if you remove a sequence, adding its PARAM_SWITCH_SEQUENCE ID to another sequence, then the new sequence can be established with that ID.)
- The Last Revelation setup is hardcoded, but in the case of F600 sequences, each sequence can be even totally different from the other one, i.e. customizable.
- This time not three, but (this number is chosen by you) 2, 3, 4 or 5 switches can be used in a sequence. Even different number in each.
- The number of possible acceptable solutions is not six per sequence now. You can choose if you want 1, 2, 3... or more acceptable solutions with the same switches.
The order of the switches in PARAM_SWITCH_SEQUENCE is the proper order of using the switches. - Which means eg. if we have switches with object ID 152, 159 and 161 in the sequence, and we type them in 152, 159, 161 order in the Script command, then Lara needs to use them in the same 152, 159, 161 order. If you want another order with the same switches, eg. 152, 161, 159, then you need to define another sequence, typing 152, 161, 159 order in it.
But, please:

a, Never have a sequence with more or less switches. For example, another sequence for the switches of ID 152, 159 and 161 should always have these three switches, never more (eg. 152, 157, 159, 161) and never less (eg. 152, 161).
b, Never use a switch in more than one series. Eg. you can have ID 152 switch of ID 152, 159 and 161 series either in a 152-159-161 or in a 152-161-159 sequence, but never use it in another series, like ID 58, 152, 170, 243.

- In the Last Revelation setup the switches were reset for the next usage if you closed the actual door being open. In this F600 setup the switches will reset in any of these cases:

a, Automatically, if the switches were all moved, but in the wrong order.
b, If the switches were all moved, in the right order, but then you make them reset with an F601.
c, If the switches were all moved, in the right order, but then you make them reset with moving back any of them into off position.
d, If NOT all the switches were moved, in any order, but then you make them reset with an F601.
e, If NOT all the switches were moved, in any order, but then you make them reset with moving back any of them into off position.

Resetting a switches after the right order won't make the thing activated by the switches antitriggered.
- In the Last Revelation setup each possible solution can be used only once. But F600 setup lets you repeat it any times. So, for example, if you have a good solution to open Door A, then the switches reset, you close later the door with another trigger somewhere else, so, more later, you can use the switches again to open this door again.
- In the Last Revelation setup all the six possible solutions of using the switches were an acceptable solution. In F600 setup there can be wrong solutions. If Lara used all the switches of the sequence now, but in a not acceptable, i.e. wrong order, then the switches will be all reset.
- The switches are not SEQUENCE_SWITCH buttons this time. I mean, the F600 setup was successfully tested only in the LEVER_SWITCH slot!
- The target can be not SEQUENCE_DOOR1 doors, but anything else. I mean, not only any doors, but any executable trigger. Moreover, the solutions don't need to be the same type even inside one series. I mean, for example, if Series1 Sequence1 is about to open a door, then Series1 Sequence2 is about to open two other doors and play an audio file, Series1 Sequence3 is about to spawn a baddy, Series1 Sequence4 is about to activate a flipmap, Series1 Sequence5 is about to close a door etc.

Very important!
Don't place any usual (SWITCH, TRIGGER) triggers under these switches.

See C110 trigger to check in which order Lara used the sequence.

See more in NG Center/Reference/Mnemonic Constants/PARAM_SWITCH_SEQUENCE.

---------- Notes: ----------

- Even if you try something which is not a LEVER SWITCH, always choose a regular switch which can have four regular animations:

a, off
b, moving to on
c, on
d, moving back to off

- Theoretically you can try even different switch types in the same sequence if you are sure that "on" and "moving back to off" animations of all the switch types of the sequence have the same animation ID in WADMerger Animation Editor.
- There are some tiny, special features of the Last Revelation setup (eg. you need to open doors first with OCB0 or OCB2 everyway), which I won't compare to F600 setup, because those tiny features were not reproduced in any form in the F600 setup.

----------------------------
#END_DOC#
601:Lara. (Holds) Reset <&> switch sequence#REMARK#Click on [Trigger's Help] button for more infos.#START_DOC#


See more in:

- F600 of this plugin,
- NG Center/Reference/Mnemonic Constants/PARAM_SWITCH_SEQUENCE.

---------- Note: -----------

If a series has more than one sequence, then you can choose any of the sequences (i.e. any of the PARAM_SWITCH_SEQUENCE ID's) of that series now to reset those switches.

----------------------------
#END_DOC#
<END>

;type here the sections for arguments used by above flipeffects

<START_EFFECT_585_T_H>
  0:LARA
 34:ENEMY_JEEP
 35:SKELETON
 37:GUIDE
 39:VON_CROY
 41:BADDY_1
 43:BADDY_2
 45:SETHA
 47:MUMMY
 49:SPHINX
 51:CROCODILE
 53:HORSEMAN
 55:SCORPION
 57:JEAN_YVES
 59:TROOPS
 61:KNIGHTS_TEMPLAR
 63:MUTANT
 65:HORSE
 67:BABOON_NORMAL
 69:BABOON_INV
 71:BABOON_SILENT
 73:WILD_BOAR
 75:HARPY
 77:DEMIGOD1
 79:DEMIGOD2
 81:DEMIGOD3
 84:BIG_BEETLE
 90:BAT
 91:DOG
 93:HAMMERHEAD
 95:SAS
102:AHMET
106:SMALL_SCORPION
127:ANIMATING1 (as AssignSlot enemy)
129:ANIMATING2 (as AssignSlot enemy)
131:ANIMATING3 (as AssignSlot enemy)
133:ANIMATING4 (as AssignSlot enemy)
135:ANIMATING5 (as AssignSlot enemy)
137:ANIMATING6 (as AssignSlot enemy)
139:ANIMATING7 (as AssignSlot enemy)
141:ANIMATING8 (as AssignSlot enemy)
143:ANIMATING9 (as AssignSlot enemy)
145:ANIMATING10 (as AssignSlot enemy)
147:ANIMATING11 (as AssignSlot enemy)
149:ANIMATING12 (as AssignSlot enemy)
151:ANIMATING13 (as AssignSlot enemy)
153:ANIMATING14 (as AssignSlot enemy)
155:ANIMATING15 (as AssignSlot enemy)
157:ANIMATING16 (as AssignSlot enemy)
181:LASER_HEAD
184:HYDRA
186:ENEMY_SUB_MARINE
189:FROG_MAN
198:ROBOT_CLEANER
199:ROBOT_STAR_WARS
206:NEW_SLOT5 (as new enemy type)
207:NEW_SLOT6 (as new enemy type)
208:NEW_SLOT7 (as new enemy type)
209:NEW_SLOT8 (as new enemy type)
210:NEW_SLOT9 (as new enemy type)
211:NEW_SLOT10 (as new enemy type)
212:NEW_SLOT11 (as new enemy type)
213:NEW_SLOT12 (as new enemy type)
214:NEW_SLOT13 (as new enemy type)
215:NEW_SLOT14 (as new enemy type)
216:NEW_SLOT15 (as new enemy type)
217:NEW_SLOT16 (as new enemy type)
218:NEW_SLOT17 (as new enemy type)
219:NEW_SLOT18 (as new enemy type)
<END>

<START_EFFECT_585_E_H>
0:Case 1
1:Case 2
2:Case 3
3:Case 4
4:Case 5
<END>

<START_EFFECT_586_T_H>
#SAME_OF#=EFFECT_585_T
<END>

<START_EFFECT_586_E_H>
#SAME_OF#=EFFECT_585_E
<END>

<START_EFFECT_587_T_H>
#REPEAT#Parameters=PARAM_VAR_MASTER,#1#9999
<END>

<START_EFFECT_588_T_H>
#REPEAT#Parameters=PARAM_DIAGNOSTIC,#1#255
<END>

<START_EFFECT_588_E_H>
0:Enable
1:Disable
<END>

<START_EFFECT_589_T_H>
0:GIN1
1:GIN2
2:GIN3
3:GIN4
4:GIN5
5:GIN6
6:GIN7
7:GIN8
8:GIN9
9:GIN10
10:GIN11
11:GIN12
12:GIN13
13:GIN14
14:GIN15
15:GIN16
16:GIN17
17:GIN18
18:GIN19
19:GIN20
20:GIN21
21:GIN22
22:GIN23
23:GIN24
24:GIN25
25:GIN26
26:GIN27
27:GIN28
28:GIN29
29:GIN30
30:GIN31
31:GIN32
32:GIN33
33:GIN34
34:GIN35
35:GIN36
36:GIN37
37:GIN38
38:GIN39
39:GIN40
40:GIN41
41:GIN42
42:GIN43
43:GIN44
44:GIN45
45:LIN1
46:LIN2
47:LIN3
48:LIN4
49:LIN5
50:LIN6
51:LIN7
52:LIN8
53:LIN9
54:LIN10
55:LIN11
56:LIN12
57:LIN13
58:LIN14
59:LIN15
60:LIN16
61:LIN17
62:LIN18
63:LIN19
64:LIN20
65:LIN21
66:LIN22
67:LIN23
68:LIN24
69:LIN25
70:LIN26
71:LIN27
72:LIN28
73:LIN29
74:LIN30
75:LIN31
76:LIN32
77:LIN33
78:LIN34
79:LIN35
80:LIN36
81:LIN37
82:LIN38
83:LIN39
84:LIN40
85:LIN41
86:LIN42
87:LIN43
88:LIN44
89:LIN45
90:Save0(S)-Last found item
91:Save1(S)-Last AnimCom item
92:Save2(S)-Item Memory item
93:Save3(S)-Lara index
94:Save4(S)-Lara hand attached
95:Save5(S)-Lara hand curr. item
96:Save6(S)-Lara hand next item
97:Save7(S)-Lara current weapon
98:Save8(S)-Lara environment
99:Save9(S)-Lara climb sector test
100:Save10(S)-Lara air
101:Save11(S)-Lara time in death
102:Save12(S)-Lara flare time in hand
103:Save13(S)-Big weapon fake item
104:Save14(S)-Lara weapon on back
105:Save15(S)-Lara poison1
106:Save16(S)-Lara poison2
107:Save17(B)-Lara special status
108:Save18(B)-Lara special status2
109:Save19(L)-Item addr.aimed by Lara
110:Save20(S)-Lara torch status
111:Save21(S)-Lara flare in hand test
112:Save22(S)-Lara automatic.aim test
113:Save23(S)-Lara horizontal rope pos.
114:Save24(L)-Lara on rope test
115:Save25(B)-Pistols in inventory
116:Save26(B)-Uzi in inventory
117:Save27(B)-Shotgun in inventory
118:Save28(B)-Crossbow in inventory
119:Save29(B)-Gren.gun in inventory
120:Save30(B)-Revolver in inventory
121:Save31(B)-Lasersight in inventory
122:Save32(B)-Binoculars in inventory
123:Save33(B)-Crowbar in inventory
124:Save34(B)-Mech.scarab in invent.
125:Save35(B)-Small w.skin in invent.
126:Save36(B)-Big waterskin in invent.
127:Save37(B)-Examine1 in inventory
128:Save38(B)-Examine2 in inventory
129:Save39(B)-Examine3 in inventory
130:Save40(B)-Puzzle Item1 in invent.
131:Save41(B)-Puzzle Item2 in invent.
132:Save42(B)-Puzzle Item3 in invent.
133:Save43(B)-Puzzle Item4 in invent.
134:Save44(B)-Puzzle Item5 in invent.
135:Save45(B)-Puzzle Item6 in invent.
136:Save46(B)-Puzzle Item7 in invent.
137:Save47(B)-Puzzle Item8 in invent.
138:Save48(B)-Puzzle Item9 in invent.
139:Save49(B)-Puzzle Item10 in invent.
140:Save50(B)-Puzzle Item11 in invent.
141:Save51(B)-Puzzle Item12 in invent.
142:Save52(B)-Puz.Combo 1-4 in invent.
143:Save53(B)-Puz.Combo 5-8 in invent.
144:Save54(B)-Key Item1-8 in invent.
145:Save55(B)-Key Item9-12 in invent.
146:Save56(B)-Pickup Items in invent.
147:Save57(B)-Quest Items in invent.
148:Save58(S)-Small medipack in inv.
149:Save59(S)-Big medipack in invent.
150:Save60(S)-Flares in inventory
151:Save61(S)-Pistols ammo in invent.
152:Save62(S)-Uzi ammo in inventory
153:Save63(S)-Revolver ammo in inv.
154:Save64(S)-Sg.norm.ammo in inv.
155:Save65(S)-Sg.wides.ammo in inv.
156:Save66(S)-Normal grenade in inv.
157:Save67(S)-Super grenade in inv.
158:Save68(S)-Flash grenade in inv.
159:Save69(S)-Normal arrow in inv.
160:Save70(S)-Poisoned arrow in inv.
161:Save71(S)-Explosive arrow in inv.
162:Save72(S)-Mech.scarab still to use
163:Save73(B)-Actual level ID
164:Save74(L)-Stat.time (=game+inv.)
165:Save75(L)-Distance travelled
166:Save76(S)-Used ammos
167:Save77(B)-Secrets found
168:Save78(B)-Used medipacks
169:Save79(L)-Screen timer
170:Save80(S)-Killed enemies
171:Save81(L)-Fog color
172:Save82(B)-Auto-aiming
173:Save83(L)-Inventory closed at item
174:Save84(S)-Slot Memory slot
175:Save85(S)-Animation memory anim.
176:Save86(L)-Game time (no Stat.time!)
177:Save87(S)-Lara last item
178:Save88(S)-Weap.anim.curr.frame
179:Save89(S)-Current weapon anim.
180:Save90(S)-T/f/w anim.curr.frame
181:Save91(S)-Curr.torch/flare/weap.an.
182:Save92(S)-(removed)
183:Save93(S)-Item enabled trigger
184:Item0(L)-Floor level below
185:Item1(L)-Contact flags
186:Item2(L)-Visible mesh flags
187:Item3(S)-Slot ID
188:Item4(S)-State ID now
189:Item5(S)-State ID next
190:Item6(S)-State ID at AI objects
191:Item7(S)-Animation Now
192:Item8(S)-Frame Now
193:Item9(S)-Actual room
194:Item10(S)-Horizontal speed
195:Item11(S)-Vertical/underwater speed
196:Item12(S)-Actual health points
197:Item13(S)-Object timer
198:Item14(S)-Object buttons
199:Item15(B)-Object status
200:Item16(S)-Unknown (grenade)
201:Item17(S)-OCB typed
202:Item18(B)-Unknown (sprite1)
203:Item19(B)-Unknown (sprite2)
204:Item20(S)-Transparence level
205:Item21(S)-Custom A
206:Item22(S)-Custom B
207:Item23(S)-Custom C
208:Item24(S)-Custom D
209:Item25(L)-Position X
210:Item26(L)-Position Y
211:Item27(L)-Position Z
212:Item28(S)-Facing vertical
213:Item29(S)-Facing horizontal
214:Item30(S)-Facing rotation
215:Item31(L)-Red ambience light
216:Item32(L)-Green ambience light
217:Item33(L)-Blue ambience light
218:Item34(L)-RGB ambience light
219:Item35(L)-Red ambience light diff.
220:Item36(L)-Green amb. light diff.
221:Item37(L)-Blue ambience light diff.
222:Item38(L)-Amb.light change degrees
223:Item39(L)-Item flags
224:GFN1
225:GFN2
226:GFN3
227:GFN4
228:GFN5
229:LFN1
230:LFN2
231:LFN3
232:LFN4
233:LFN5
234:Invt0(S)-Item Slot
235:Invt1(S)-Top border (vertical pos.)
236:Invt2(S)-Distance of camera
237:Invt3(S)-X facing
238:Invt4(S)-Y facing
239:Invt5(S)-Z facing
240:Invt6(S)-View flags
241:Invt7(S)-String of name
242:Invt8(L)-Unknown
243:Invt9(S)-Type flags
244:Code0(S)-Audio on channel1
245:Code1(S)-Audio on channel2
246:Code2(B)-Script Options flags
247:Code3(B)-Level ID
248:Code4(S)-Script Level flags
249:Code5(L)-Earthquake intensity
250:Code6(S)-Screen width (pixels)
251:Code7(S)-Screen height (pixels)
252:Code8(L)-Keyboard command hit
253:Code9(S)-Dash bar value
254:Code10(L)-Inventory item required
255:Code11(L)-Inventory item just chosen
256:Code12(L)-Game+menus all time
257:Code13(L)-Flyby-in-progress test
258:Code14(B)-New game/save loaded
259:Code15(L)-Music volume
260:Code16(L)-Sound SFX volume
261:Code17(L)-Camera mode now
262:Code18(L)-Camera mode next
263:Code19(B)-Speed layer1
264:Code20(B)-Speed layer2
265:Code21(B)-Fog bulbs disabled
266:Code22(L)-Stat.time (=game+inv.)
267:Code23(S)-Current vehicle index
268:Slot0(S)-Number of meshes
269:Slot1(S)-First mesh index
270:Slot2(L)-Pointer (initialization proc.)
271:Slot3(L)-Pointer (main cont.proc.)
272:Slot4(L)-Pointer (special floor proc.)
273:Slot5(L)-Pointer (special ceil.proc.)
274:Slot6(L)-Pointer (emitter procedure)
275:Slot7(L)-Pointer (collision procedure)
276:Slot8(S)-Distance to enable MIP
277:Slot9(S)-Maximal health points
278:Slot10(S)-Distance to detect Lara
279:Slot11(S)-Unknown (to Custom B)
280:Slot12(S)-Footstep (shadow)
281:Slot13(S)-Test attack Lara
282:Slot14(S)-Main flags
283:Slot15(L)-Pointer (draw extra proc.)
284:Slot16(L)-Shatterable meshes
285:Slot17(L)-Unknown
286:Slot18(S)-First animation index
287:Anim0(B)-Frame rate
288:Anim1(B)-Frame size (byte/frame)
289:Anim2(S)-State ID
290:Anim3(S)-Unknown
291:Anim4(S)-Speed
292:Anim5(S)-Low Acceleration
293:Anim6(S)-High Acceleration
294:Anim7(S)-Unknown
295:Anim8(S)-Next speed
296:Anim9(S)-Next Low Acceleration
297:Anim10(S)-Next High Acceleration
298:Anim11(S)-First abs. Frame index
299:Anim12(S)-Last abs. Frame index
300:Anim13(S)-Next Animation
301:Anim14(S)-Next Frame
302:Anim15(S)-State Changes amount
303:Anim16(S)-Abs.ID: 1st State Change
304:Anim17(S)-AnimCommands amount
305:Anim18(S)-Abs.ID: 1st AnimComm.
<END>

<START_EFFECT_590_T_H>
#SAME_OF#=EFFECT_589_T
<END>

<START_EFFECT_591_T_H>
#REPEAT#Parameters=PARAM_PRINT_VAR,#1#255
<END>

<START_EFFECT_591_E_H>
0:Print
1:Remove
<END>

<START_EFFECT_592_T_H>
#REPEAT#Level #1#99
<END>

<START_EFFECT_592_E_H>
#REPEAT#Lara_Start_Pos with OCB #1#9
0:Lara object
<END>

<START_EFFECT_593_T_H>
#REPEAT#Parameters=PARAM_MENU_TRIGGER,#1#9999
<END>

<START_EFFECT_594_T_H>
#REPEAT#Game Backup #1#128
<END>

<START_EFFECT_594_E_H>
0:Standard way (progress bar + load camera screen)
1:Hidden screen (let last game screen and load in background)
2:Black screen (Set black screen and no progress bar)
<END>

<START_EFFECT_595_T_H>
#REPEAT#Parameters=PARAM_SPRITE_DISPLAY,#1#255
<END>

<START_EFFECT_595_E_H>
0:Show
1:Hide
<END>

<START_EFFECT_596_T_H>
#REPEAT#Parameters=PARAM_RAINDROP,#1#255
<END>

<START_EFFECT_596_E_H>
0:Enable
1:Disable
<END>

<START_EFFECT_597_T_H>
0:Start
1:Stop
<END>

<START_EFFECT_598_T_H>
0:Start
1:Stop
<END>

<START_EFFECT_599_T_H>
#REPEAT#Sign,#1#255
<END>

<START_EFFECT_599_E_H>
0:Activate
1:Deactivate
<END>

<START_EFFECT_600_T_H>
#REPEAT#Parameters=PARAM_SWITCH_SEQUENCE,#1#100
<END>

<START_EFFECT_600_E_H>
0:Establish
1:Remove
<END>

<START_EFFECT_601_T_H>
#REPEAT#Parameters=PARAM_SWITCH_SEQUENCE,#1#100
<END>


;------------------- Section for Action triggers: description of the trigger -------------------------------------
<START_TRIGGERWHAT_11_T_H>
<END>

;type here the sections for argument of above action triggers






;------------------- Section for Condition triggers: description of the trigger -------------------------------------
<START_TRIGGERTYPE_12_T_H>
110:Lara. (Holds) Lara uses the switches of <#> sequence #REMARK#Click on [Trigger's Help] button for more infos.#START_DOC#

Important!
Don't place this trigger under the switches of the sequence.

See more in:

- F600 of this plugin,
- NG Center/Reference/Mnemonic Constants/PARAM_SWITCH_SEQUENCE.

---------- Notes: ------------

- You can use this condition even placed in the map. But in this case the condition will not be true when all the switches have been moved into this proper position. Now first you need to move the switches into this proper position, then, later, when you reach this condition, the condition will be checked.
So, instead, I recommend using this condition as a globaltrigger condition, so the condition can be checked in the moment when all the switches have been moved into this proper position.
- If the event can be multiplied, then I recommend a "single shot resumed" flag.
For example, a short flash of F355 of trng.dll can be multiplied. I mean, short flashes executed after each other makes a long flash, so short flashes can be multiplied. If you execute a multipliable event when the switches are used in the proper order, then the event will be surely multiplied. So, eg. executing a short flash when the switches in the right order results it will be a long (infinite, till the switches reset) flash.
You can solve this problem, eg. using an FGT_SINGLE_SHOT_RESUMED flag in the GlobalTrigger.
- I also recommend a "single shot" or "single shot resumed" flag, if you want to turn the event off.
For example, if the switches of a sequence opens a door, then it wants to open it again and again, after having opened it. Naturally, nothing happens, because the door is already open. But if you want to perform an antitrigger now to close the door, then it won't happen, because the "it wants to open it again and again" thing will annul it.
You can solve this problem, eg. also using an FGT_SINGLE_SHOT_RESUMED flag in the GlobalTrigger.

----------------------------
#END_DOC#
111:Trigger management. This condition with <#> sign has already been activated #REMARK#See F599 of this plugin for more infos.
112:Camera. The actual camera has <#> parameters #REMARK#Click on [Trigger's Help] button for more infos.#START_DOC#
Use this condition to check any of these parameters of the actual (chase, look, combat, static, flyby) camera:

- the room ID/flipmap ID of the camera or its target,
- the room type (horizon, water, fliproom etc.) of the camera or its target,
- the distance (3D, X, Y, Z) between the camera and its target,
- the vertical distance:
a, between the camera and the nearest solid floor below that/nearest solid ceiling above that,
b, between the camera and the water surface below/above that.
- the X/Y/Z camera angle, compared to the east/west/north/south/floor/ceiling cardinal points (based on the angle between the camera and its target).

See more in NG Center/Reference/Mnemonic Constants/PARAM_ACTUAL_CAM.

---------- Notes: ----------

- In the case of flyby camera sequences the "camera" is naturally always the actual position of the sequence, not a camera of the sequence placed in the map.
- I suspect, but I am not sure that in the case of flyby cameras usually the closest camera of the two adjacent cameras of the sequence will be considered as the target now. But eg. you can also set Bit3 on Camera Properties Panel, to track Lara.
- If you want to check the type (chase, look, combat, static, flyby) of the actual camera, then see C223 of my first (Plugin_AkyVMix01) plugin. (Which could be buggy for some camera types when you also have the "raindrop" feature of the present plugin enabled at the same time.)
- The condition can also work with some "special camera", like lasersight, binoculars.

----------------------------
#END_DOC#
113:Finish. The previous level ID is <#> #REMARK#Click on [Trigger's Help] button for more infos.#START_DOC#
This condition is useful in these cases:

- If more than one Finish trigger leads to the current level, and you'd like to know which was the ID of the previous level. (ID based on the order of the levels in the script.) - Choose "title" to check if Lara has come here with starting a new game.
- If you, being in the title, would like to know which was the ID of level, from which you have just come to the title, by death, clicking on "Exit to title", or activating a Finish trigger.

---------- Notes: -----------

- "Start" is useable, if you has come to the title by NOT leaving another level, i.e if you are in the title because you have just launched tomb4.exe - either for a new game or for loading a savegame.
- Don't misunderstand: if you load a level, then the "previous" level is not wherefrom you load the level. It is the level, wherefrom you reached the level loaded, before saving that savegame, with a Finish trigger (or starting a new game, if the "previous" level is the title).

----------------------------
#END_DOC#
114:Variables. Examine <#> relation #REMARK#Click on [Trigger's Help] button for more infos.#START_DOC#
You can compare the values of new and old variables and memory zone fields to each other or another number, with this trigger.
And you can also check here if a bit is set or clear in those variables/fields.

See F587 of this plugin for more info.

See more in NG Center/Reference/Mnemonic Constants/PARAM_VAR_MASTER.

---------- Note: -----------

I don't recommend "equal" conditions with floating values. Probably these relations will fail many times. Instead, choose a little interval. For example, if you want to check "if variable is 100.572", you should check "if variable is more than 100.500 and less than 101.000", with two conditions at the same time.

----------------------------
#END_DOC#
115:Enemy. The shadow of <#> enemy type (or Lara) is (E) seeable/removed #REMARK#See F585/F586 of this plugin to set this.
<END>

;type here the sections for arguments of above conditional triggers

<START_CONDITION_110_O_H>
#REPEAT#Parameters=PARAM_SWITCH_SEQUENCE,#1#100
<END>

<START_CONDITION_111_O_H>
#REPEAT#Sign,#1#255
<END>

<START_CONDITION_112_O_H>
#REPEAT#Parameters=PARAM_ACTUAL_CAM,#1#1023
<END>

<START_CONDITION_113_O_H>
#REPEAT#Level #1#99
0:Title
100:Start
<END>

<START_CONDITION_114_O_H>
#REPEAT#Parameters=PARAM_VAR_MASTER,#1#1023
<END>

<START_CONDITION_115_O_H>
#SAME_OF#=EFFECT_585_T
<END>

<START_CONDITION_115_B_H>
0:Seeable (restored or never removed)
1:Removed
<END>


