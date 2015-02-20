<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 *
 * Override: add a grouped-row div around each group single grouping
 */
?>
<div class="grouped-row">
<?php if (!empty($title)): ?>
  <div class="title-wrapper">
    <div class="title-wrapper-inner">
      <h3><?php print $title; ?></h3>
      </div>
  </div>
<?php endif; ?>
  <div class="content-wrapper">
    <div class="content-wrapper-inner">
      <?php foreach ($rows as $id => $row): ?>
        <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
          <?php print $row; ?>
        </div>
      <?php endforeach; ?>
    </div>
  </div>
</div>
