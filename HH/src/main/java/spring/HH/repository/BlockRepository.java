package spring.HH.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import spring.HH.domain.Block;

public interface BlockRepository extends JpaRepository<Block, Long> {
}
