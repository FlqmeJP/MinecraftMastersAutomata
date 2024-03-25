package com.example.firesword;

import org.bukkit.Bukkit;
import org.bukkit.Material;
import org.bukkit.block.Block;
import org.bukkit.entity.EntityType;
import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.player.PlayerInteractEvent;
import org.bukkit.plugin.java.JavaPlugin;
import org.bukkit.scheduler.BukkitRunnable;

public final class FireSword extends JavaPlugin implements Listener {

    @Override
    public void onEnable() {
        // Plugin startup logic
        getServer().getPluginManager().registerEvents(this, this);
        getLogger().info("FireSword plugin has been enabled");
    }

    @Override
    public void onDisable() {
        // Plugin shutdown logic
        getLogger().info("FireSword plugin has been disabled");
    }

    @EventHandler
    public void onPlayerInteract(PlayerInteractEvent event) {
        Player player = event.getPlayer();
        if (event.getAction().toString().contains("RIGHT_CLICK") && player.getInventory().getItemInMainHand().getType() == Material.DIAMOND_SWORD) {
            Block targetBlock = player.getTargetBlock(null, 100);
            spreadFireAndExplode(targetBlock);
        } else if (event.getAction().toString().contains("LEFT_CLICK") && player.getInventory().getItemInMainHand().getType() == Material.DIAMOND_SWORD) {
            Block targetBlock = player.getTargetBlock(null, 100);
            spreadIce(targetBlock);
        }
    }

    private void spreadFireAndExplode(Block targetBlock) {
        // 100ブロック先まで炎を展開
        targetBlock.setType(Material.FIRE);

        // 5秒後に爆発を引き起こす
        new BukkitRunnable() {
            @Override
            public void run() {
                targetBlock.getWorld().createExplosion(targetBlock.getLocation(), 5.0f);
                createParticle(targetBlock);
            }
        }.runTaskLater(this, 100L); // 5秒後 (20ticks * 5 = 100)
    }

    private void spreadIce(Block targetBlock) {
        // 20ブロックの範囲内に氷を展開
        int radius = 20;
        int blockCount = 0;
        for (int x = -radius; x <= radius; x++) {
            for (int y = -radius; y <= radius; y++) {
                for (int z = -radius; z <= radius; z++) {
                    Block block = targetBlock.getRelative(x, y, z);
                    if (block.getLocation().distance(targetBlock.getLocation()) <= radius && block.getType() == Material.AIR) {
                        block.setType(Material.ICE);
                        blockCount++;
                    }
                }
            }
        }
        System.out.println("Spread " + blockCount + " ice blocks.");
    }

    private void createParticle(Block block) {
        Bukkit.getServer().getScheduler().runTaskLater(this, () -> {
            block.getWorld().spawnParticle(org.bukkit.Particle.EXPLOSION_LARGE, block.getLocation(), 100);
        }, 0L); // 0tick からパーティクルを生成
    }
}
