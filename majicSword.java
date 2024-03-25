package com.example.majicsword;

import org.bukkit.Particle;
import org.bukkit.plugin.java.JavaPlugin;
import org.bukkit.Bukkit;
import org.bukkit.Location;
import org.bukkit.Material;
import org.bukkit.entity.Entity;
import org.bukkit.entity.EntityType;
import org.bukkit.entity.LivingEntity;
import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.player.PlayerInteractEvent;
import org.bukkit.util.Vector;

public final class MajicSword extends JavaPlugin implements Listener {

    @Override
    public void onEnable() {
        // Plugin startup logic
        getServer().getPluginManager().registerEvents(this, this);
        getLogger().info("MajicSword plugin has been enabled");
    }

    @Override
    public void onDisable() {
        // Plugin shutdown logic
        getLogger().info("MajicSword plugin has been disabled");
    }

    @EventHandler
    public void onPlayerInteract(PlayerInteractEvent e) {
        Player player = e.getPlayer();
        if (player.getInventory().getItemInMainHand().getType() == Material.DIAMOND_SWORD) {

            Location startLocation = player.getLocation().add(0, 1, 0);

            Vector direction = player.getEyeLocation().getDirection();
            double maxDistance = 50;

            Location targetLocation = startLocation.clone();
            for (int i = 0; i < maxDistance; i++) {
                targetLocation.add(direction);
                if (targetLocation.getBlock().getType() != Material.AIR) {
                    break;
                }

                player.getWorld().spawnParticle(org.bukkit.Particle.END_ROD, targetLocation, 1, 0, 0, 0, 0);

                for(Entity entity : player.getWorld().getNearbyEntities(targetLocation,1,1,1)){
                    if(entity instanceof LivingEntity && !(entity instanceof Player)){

                        ((LivingEntity) entity).damage(10);
                        player.getWorld().createExplosion(targetLocation,50);
                        return;
                    }
                }
            }
        }
    }
}
